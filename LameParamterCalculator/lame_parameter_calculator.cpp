//Calculate Lame parameters
//mu = E/(2*(1+\nu))
//\lambda = E*\nu/((1+\mu)*(1-2*\nu))
#include<iostream>
#include<string>

int main()
{
   double mu, lambda, nu, E;
   //Get input as E and nu
   std::string line(50, '-');
   std::cout << line << std::endl;
   std::cout << "Running program to calculate the lame parameters" << std::endl;
   std::cout << line << std::endl;
change_E:
   do{
   std::cout << "Enter E and nu " << std::endl;
   std::cout << "Enter -1 for exit or 0 for change" << std::endl;
   std::cin >> E;
   if (E == -1) break;
   if (E == 0) goto change;
   std::cin >> nu;
   std::cout << " Entered values are : " << std::endl;
   std::cout << "\t \t E : " << E << std::endl;
   std::cout << "\t \t nu : " << nu << std::endl;
   lambda = E*nu/((1+nu)*(1-2*nu));
   mu     = E/(2*(1+nu));
   std::cout << " Output values are : " << std::endl;
   std::cout << "\t \t lambda : " << lambda << std::endl;
   std::cout << "\t \t mu : " << mu << std::endl;
   std::cout << line << std::endl;
   }while (E!= -1);

change:
   do{
   std::cout << "Enter lambda and mu " << std::endl;
   std::cout << "Enter -1 for exit or 0 for change" << std::endl;
   std::cin >> lambda;
   if (lambda == -1) break;
   if (lambda == 0) goto change_E;
   std::cin >> mu;
   std::cout << " Entered values are : " << std::endl;
   std::cout << "\t \t lambda : " << lambda << std::endl;
   std::cout << "\t \t mu : " << mu << std::endl;
   E  = mu*(3*lambda + 3*mu)/(lambda + mu);
   nu = lambda/(2*(lambda + mu));
   std::cout << " Output values are : " << std::endl;
   std::cout << "\t \t E : " << E << std::endl;
   std::cout << "\t \t nu : " << nu << std::endl;
   std::cout << line << std::endl;
   }while (lambda!= -1);

}
