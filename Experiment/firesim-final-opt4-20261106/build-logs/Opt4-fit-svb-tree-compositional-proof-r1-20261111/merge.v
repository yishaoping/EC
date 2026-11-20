module MergeLemma(input av,bv, input[68:0] ak,bk,input[4:0] ai,bi,output ok,output mutant_ok);
wire choose_b=bv&(~av|bk>ak);wire v=av|bv;wire[68:0] k=choose_b?bk:ak;wire[4:0] i=choose_b?bi:ai;
assign ok= (v==(av|bv)) && (!v || ((choose_b?bv:av) && k==(choose_b?bk:ak) && i==(choose_b?bi:ai))) && (!av || k>=ak) && (!bv || k>=bk);
assign mutant_ok=(!v || k==(choose_b?ak:bk));
endmodule
