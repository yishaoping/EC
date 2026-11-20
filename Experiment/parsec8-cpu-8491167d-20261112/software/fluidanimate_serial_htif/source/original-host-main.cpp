extern void InitSim(const char*),AdvanceFrame(),SaveFile(const char*);int main(){InitSim("selected.fluid");AdvanceFrame();SaveFile("original-reference.fluid");}
