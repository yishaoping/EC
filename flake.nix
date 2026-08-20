{
  description = "Fast Clang/Verilator environment for EC Chipyard simulations";

  inputs = {
    nixpkgs.url =
      "github:NixOS/nixpkgs/205fd4226592cc83fd4c0885a3e4c9c400efabb5";
    nixpkgs-tools.url =
      "github:NixOS/nixpkgs/569d578509928497eddc3fdbf94a799027050be4";
  };

  nixConfig = {
    bash-prompt-prefix = "(EC) ";
  };

  outputs = { self, nixpkgs, nixpkgs-tools }:
    let
      system = "x86_64-linux";
      pkgs = import nixpkgs { inherit system; };
      toolsPkgs = import nixpkgs-tools { inherit system; };

      # Keep Verilator and Clang on the reference commit's nixpkgs/glibc 2.38
      # baseline so they remain compatible with the existing Chipyard tools.
      clangVerilator = (pkgs.verilator.override {
        stdenv = pkgs.clangStdenv;
      }).overrideAttrs (_old: {
        version = "5.048";
        src = pkgs.fetchFromGitHub {
          owner = "verilator";
          repo = "verilator";
          rev = "v5.048";
          hash = "sha256-xvqqgbW7L07+NBYzGN2KLhwir58ByShxo4VVPI3pgZk=";
        };
        doCheck = false;
      });
    in
    {
      packages.${system}.verilator = clangVerilator;

      devShells.${system}.default = pkgs.mkShellNoCC {
        name = "EC";
        packages = [
          pkgs.bash
          pkgs.bc
          toolsPkgs.ccache
          pkgs.clang
          pkgs.coreutils
          pkgs.git
          pkgs.gnumake
          pkgs.numactl
          pkgs.perl
          pkgs.python3
          pkgs.which
          pkgs.zlib
          clangVerilator
        ];

        shellHook = ''
          export EC_ENV_NAME=EC
          ec_repo_root="$(git rev-parse --show-toplevel 2>/dev/null || pwd)"
          chipyard_root="$ec_repo_root/chipyard"
          chipyard_conda="$chipyard_root/.conda-env"

          if [[ ! -d "$chipyard_conda/riscv-tools" ]]; then
            echo "nix develop: missing $chipyard_conda/riscv-tools" >&2
            echo "Run Chipyard's build-setup.sh before building a simulator." >&2
          else
            export RISCV="$chipyard_conda/riscv-tools"
            export JAVA_HOME="$chipyard_conda/lib/jvm"
            # Put the conda JDK (17) first so `java`/sbt never pick up the
            # system JDK 21, which sbt 1.8.2 cannot run on.
            export PATH="$JAVA_HOME/bin:$RISCV/bin:$PATH:$chipyard_conda/bin:$chipyard_root/bin"
            # Pin sbt to the conda JDK 17 explicitly: the sbt launcher honours
            # `-java-home`, so this stays correct even if a terminal's PATH
            # still resolves `java` to the system JDK 21.
            export SBT_BIN="$chipyard_conda/bin/sbt -java-home $chipyard_conda/lib/jvm"
            export FIRTOOL_BIN="$chipyard_conda/bin/firtool"
          fi

          # Verilator records Clang in verilated.mk, and these overrides also
          # cover auxiliary C/C++ builds such as DRAMSim2.
          export CC="${pkgs.clang}/bin/clang"
          export CXX="${pkgs.clang}/bin/clang++"
          export OBJCACHE="${toolsPkgs.ccache}/bin/ccache"
          export CCACHE_BASEDIR="$ec_repo_root"
          export CCACHE_DIR="''${XDG_CACHE_HOME:-$HOME/.cache}/ec-verilator-ccache"

          # FST waveform tracing (--trace-fst) in Verilator 5.x needs zlib.
          # Expose its headers/lib so the generated model's C++ compile finds
          # zlib.h and -lz (clang honours CPLUS_INCLUDE_PATH / LIBRARY_PATH).
          export CPLUS_INCLUDE_PATH="${pkgs.zlib.dev}/include:''${CPLUS_INCLUDE_PATH:-}"
          export LIBRARY_PATH="${pkgs.zlib}/lib:''${LIBRARY_PATH:-}"
          unset VERILATOR_ROOT

          unset ec_repo_root chipyard_root chipyard_conda
        '';
      };
    };
}
