 #include <iostream>
 using namespace std;
 class simple_calculator {
 public:
     int a, b, c;
     char ope;
     void getfirst();     
     void getoperator();
     void getsecond();
     void add();
     void sub();
     void multiply();
     void divide();

 } obj;
 int main()

 {
 cout<<"******************************************"<<endl;
 cout<<"**         SIMPLE CALCULATOR            **"<<endl;
 cout<<"******************************************"<<endl;

     obj.getfirst();
     while (1)

     {
         obj.getoperator();
         if (obj.ope == '=')
         {

             cout << "FINAL ANSWER IS :: " << obj.a<<endl;
             break;

         }
         obj.getsecond();

         if (obj.ope == '+')
         {
            
             obj.add();
         }
         else if (obj.ope == '-')
         {             obj.sub();
         }
         else if (obj.ope == '*')
         {
             obj.multiply();
         }
         else if (obj.ope == '/')
         {
             obj.divide();
         }

         else
         {
             cout << "INVALID OPERTOR :: " << endl;        }
     }
     return 0;
 }
 void simple_calculator ::getfirst()
 {
     cout << "ENTER THE VALUE OF A :: ";     cin >> a;
 } void simple_calculator::getoperator() {
     cout << "ENTER THE OPERATOR (+ , - , * , /) :: ";
     cin >> ope;
 }

 void simple_calculator::getsecond()
 {
     cout << "ENTER THE VALUE OF B :: ";
     cin >> b;
 }
 void simple_calculator::add()
 {

     c = a + b;    
	 cout << a << " + " << b << " = " << c << endl;
     a = c;
 }

 void simple_calculator::sub()
 {

     c = a - b;
     cout << a << "-" << b << " = " << c << endl;
     a = c;
 }

 void simple_calculator::multiply()
 {

     c = a * b;
     cout << a << "*" << b << " = " << c << endl;    
	 a = c;
 }
 void simple_calculator::divide()
 {
     if (b == 0)
     {
         cout << "Error: Division by zero! " << endl;
     }     else
     {
         c = a / b;
         cout  << a << "/" << b << " = " << c << endl;
         a = c;
     }
 }


