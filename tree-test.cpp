#include <iostream>
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"

float xyzToEnergy(int x, int y, int z)
{
    return x*y + z;
}

int main()
{
    //create a tree file tree1.root - create the file, the Tree and a few branches
    TFile f("tree.root","recreate");
    TTree t1("MyTree","a simple Tree with simple variables");
    Float_t x, y, z, energy;
    Int_t ev;
    t1.Branch("x",&x,"x/F");
    t1.Branch("y",&y,"y/F");
    t1.Branch("z",&z,"z/F");
    t1.Branch("energy",&energy,"energy/F");
    t1.Branch("ev",&ev,"ev/I");
    
    ev = 1;
    //fill the tree
    for (Int_t i=0; i<10; i++) {
        for (Int_t j=0; j<10; j++) {
            for (Int_t k=0; k<10; k++) {
                
                x = i;
                y = j;
                z = k;
                energy = xyzToEnergy(x,y,z);
                t1.Fill();
                ev++;
            }
        }
    }
    //save the Tree heade; the file will be automatically closed
    //when going out of the function scope
    t1.Write();
    return 0;
}
