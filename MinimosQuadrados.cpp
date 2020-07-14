//
// Método dos minimos quadrados
//
// Gera uma reta com o menor erro a partir de uma colecao de dados  :
//
//      y = ax + b 
//
//   Conferido e funcionando .. .
/*
#include <MinimosQuadrados.h>
#include <IOarquivos.h>

using namespace std;

//vetor a , vetor b (meio) , vetor c , vetor d (solucao), tamanho da matriz  ;
void MinimosQuadrados(vector<double> &_x , vector<double> &_y )
{
    int n(_x.size());
    vector <double>::iterator itrxdbl , itrydbl;
    double somxy(0) , somx(0), somy(0), somxquad(0),quadsomx(0); 
    double y , x ; 
    double a(0),b(0);
    
    // calculando o valor de a 
    itrydbl=_y.begin(); 
    for(itrxdbl=_x.begin() ; itrxdbl !=_x.end() ; itrxdbl++)
    {
        y=*(itrydbl);
        x=*(itrxdbl);
        cout << x  << " " << y << endl ; 
        somxy+= (x*y);
        
        somx+=x;
        
        somy+=y;
        
        somxquad+= (x *x) ; 
       
        itrydbl++;
    }
    quadsomx = somx*somx;
    
    a= ( ( (n*somxy) - (somx*somy))   ) / (( (n*somxquad)-quadsomx));
    b= ((somxquad*somy) - (somx*somxy) )/(((n*somxquad)-quadsomx));
    cout << " y = " << a << " x + "<< b << endl ; 
            
    cout << "Escrevendo em arquivo " << endl ;     
      
    double incremento(_x[0]),fx(0);
    
    do
      {
        incremento+=0.1;
        fx= (a*incremento) + b ;
        cout << incremento << " " << fx<< endl ; 
        
        EscreveArq("saida.mmq",incremento,fx);
      }while (incremento< _x[n-1]);

      cout << "Fim . Verifique o arqvuio saida.mmq na mesma pasta onde o codigo foi executado" << endl ; 

   //return 0 ;  
}
*/