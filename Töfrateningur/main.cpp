#include <iostream>
using namespace std;
const int max_staerd_tenings = 100;
void input_fall(int galdra[][max_staerd_tenings], int staerd_tenings);
void galgrareikningur(int galdra[][max_staerd_tenings], int staerd_tenings);

int main()
{
    
    
    int staerd_tenings;
    
    cin >> staerd_tenings;
    
    int galdra[max_staerd_tenings][max_staerd_tenings];
  
    //þessi for lykkja er til þess að 0-stilla fylkið
    for(int x = 0; x < staerd_tenings; x++)
    {
        
        for( int y = 0; y < staerd_tenings; y++)
        {
            
            galdra[x][y] = 0;
            
        }
    }

    
    input_fall(galdra, staerd_tenings);
   
    galgrareikningur(galdra, staerd_tenings);
    
    return 0;
}

void input_fall(int galdra[][max_staerd_tenings], int staerd_tenings)
{
    for(int x = 0; x < staerd_tenings; x++)
    {
        for( int y = 0; y < staerd_tenings; y++)
        {
            cin >> galdra[x][y];
            
        }
    }
    
}
void galgrareikningur(int galdra[][max_staerd_tenings], int staerd_tenings)
{
    int nytt_fylki_telur_rod [staerd_tenings];
    int nytt_fylki_telur_dalk [staerd_tenings];
    int summa_hornalinu_HtV = 0;
    int summa_hornalinu_VtH = 0;
    
    //þessi forlykkja er til að 0-stilla bæði nýju fylkin sem voru tilgreind her að ofan.
    
    for(int i = 0; i < staerd_tenings; i++)
    {
        nytt_fylki_telur_dalk[i] = 0;
        nytt_fylki_telur_rod[i] = 0;
    }
    
    
    //þessar forlykkjur lesa inn í fylkið nytt_fylki_telur_rod úr galdrafylkinu. Fer inn í fyrri lykkjun og þá verður x=0 svo inní seinni þá verður y=0. þá er það sem fer í fyrsta sætið í nyja fylkinu er það sem er í sæti 0,0 í galdrafylkinu. Svo helduru áfram í ynnrti lykkujunni og í hólf 2 í nýja fylkinu er það sem er í sæti (0,1) í galdrafylkinu. 
    for(int x = 0; x < staerd_tenings; x++)
    {
        for(int y = 0; y < staerd_tenings; y++)
        {
            nytt_fylki_telur_rod[x] += galdra[x][y];
            
        }
    }
    
    
    //þessi lykkja virkar alveg eins og síðasta lykkja nema hún setur inní nytt_fylki_telur_dalk. Það gerist með að víxla x og y inní ynnri lykkjunni.
    for(int x = 0; x < staerd_tenings; x++)
    {
        for(int y = 0; y < staerd_tenings; y++)
        {
            nytt_fylki_telur_dalk[x] += galdra[y][x];
            
        }
    }
  
    //þessi lykkja reiknar summu hornalínunar frá Hægri til Vinstri. Hún byrjar á að fara inn í lykkjuna og þá verður (0,0) í galdrafylkinu það sem bætist við summuna. Þegar lykkjan keyrist aftur þá hækkar bæði lína og röð um 1 því það er x í bæði fyrri og seinni. Þannig summar lykkjan  saman það sem er í hallalínunni.
    for(int x = 0; x < staerd_tenings; x++)
    {
        summa_hornalinu_VtH += galdra[x][x];
    }
    //Áður en er farið inn í þessa lykkju er búin til ný breyta til að geta talið hornalínuna frá Vinstri til Hægri. Brytan er forstyllt þannig hún verði einum minna er stærð galdrateningsins vegna þess að fylki byrja að tela frá 0. Þá er það fyrsta sem fer inn í VtilH summuna er (0,(stærð tenings -1)) sem er bara (0,2) í þessu tilviki. Þegar lykkjan keyrir aftur verður það næsta sem fer inn (1,1) o.s.frv.
    
    int HtilV = staerd_tenings - 1;
    
    for(int x = 0; x < staerd_tenings; x++)
    {
        summa_hornalinu_HtV += galdra[x][HtilV];
        HtilV--;
    }
    
    //Þessi forlykkja fer í gegnum nýju fylkin og ber þau saman. 
    for(int i = 0; i < staerd_tenings; i++)
    {
        //Þessi iffsettning ber saman hólf i og i í báðum nýju fylkjunum. Ef þau eru ekki eins outputar forritið "ekki galdraferningur"
        if (nytt_fylki_telur_dalk[i] != nytt_fylki_telur_rod[i])
        {
            cout << "ekki galdraferningur" << endl;
            
            return; 
        }
        //Þessi ifsetting ber saman nytt_fylki_telur_dalk við summa_hornalinu_HtV. Ég þarf ekki að gera það sama fyrir nytt_fylki_telur_rod því ég veit að það sé sama og nytt_fylki_telur_dalk.
        else if(nytt_fylki_telur_dalk[i] != summa_hornalinu_HtV)
        {
            cout << "ekki galdraferningur" << endl;
            
            return; 
        }
        //Eina sem á þá eftir að bera saman eru hornalínurnar og það er gert með þessari ifsettingu.
        else if(summa_hornalinu_VtH != summa_hornalinu_HtV)
        {
            cout << "ekki galdraferningur" << endl;
            
            return; 
        }
    }
    
    cout << "galdraferningur" << endl;
    
    return; 
    
}