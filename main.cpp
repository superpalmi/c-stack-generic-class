#include "stack.h"
#include <iostream> // std::cout
#include <stdexcept> // std::out_of_range
#include <cassert>
#include <vector>

struct multiplo2 {
  bool operator()(const int &a) const {
    return ((a%2) == 0);
  }
};

struct voce {
	std::string cognome; 
	std::string nome; 
	int ntel; 
	
	voce() {}
	
	voce(const std::string &c, 
			const std::string &n, 
			const int &t) : 
			cognome(c), nome(n), ntel(t){} 
};

std::ostream &operator<<(std::ostream &os, const voce &v) {
	os << v.cognome << " " << v.nome << " " << v.ntel;
	return os;
}

struct string_equals{
  bool operator()(const std::string &s) const{
    return (s == "otto");
  }

};


struct same_name{
 const bool operator()(const voce &a) const{
    return (a.nome=="Riccardo");
  }

};





void test_svuotamento(){

  std::cout<<"++++ TEST SVUOTAMENTO ++++"<<std::endl;


    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.empty();
    std::cout<<s<<std::endl;


}


void test_stack_base(){


   std::cout<<"++++ TEST STACK BASE ++++ "<<std::endl;



    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(9);
    s.push(10);
    s.push(11);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    std::cout<<"numero elementi: " << s.get_size()<< std::endl;
    std::cout<<"POP"<<std::endl;
    s.pop();
    std::cout<<"in cima ho: " << s.top() << std::endl;
    std::cout<<"numero elementi: " << s.get_size()<< std::endl;

    std::cout<<"iterator"<<std::endl;
    stack<int>::const_iterator b, e;
      b=s.const_begin();
      e=s.const_end();
      
      stack<int>s2(b, e);

      std::cout<<s2<<std::endl;

      std::cout<<"POP"<<std::endl;
      

      s2.pop();
      std::cout<<"in cima ho: " << s2.top() << std::endl;

      std::cout<<"iterator"<<std::endl;



      stack<int>::const_iterator b2, e2;
      b2=s.const_begin();
      e2=s.const_end();

      for(; b2 != e2; ++b2) {
      std::cout << *b2 << std::endl;
      }
     // std::cout << *b2 << std::endl;

      std::cout<<"in cima ho: " << s.top() << std::endl;

      multiplo2 mul;
      removeIf(s, mul);
      std::cout<<"iterator 3"<<std::endl;
      stack<int>::const_iterator b3, e3;
      b3=s.const_begin();
      e3=s.const_end();
      stack<int> s3;
      for(; b3 != e3; ++b3) {
       s3.push(*b3);
      }
      //std::cout << *b3 << std::endl;
      std::cout<<"in cima ho "<< s3.top()<<std::endl;


     // std::cout<<&b3<<std::endl;
      stack<int>::const_iterator b4, e4;
      b4=s.const_begin();
      e4=s.const_end();

      std::cout<<"punto due " <<std::endl;
   
     stack<int> s_it(b4, e4);
      for(; b4 != e4; ++b4) {
         std::cout<<*b4<<std::endl;
      }

      

     // std::cout<<s<<std::endl;

      s_it.empty();
     
      
     
      





}

void test_replace(){

  stack<int> s;
    s.push(1);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(2);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(3);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(4);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(5);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(6);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(7);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(8);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(9);
    std::cout<<"in cima ho: " << s.top() << std::endl;
    s.push(10);
    std::cout<<"in cima ho: " << s.top() << std::endl;


  stack<int>::const_iterator b5, e5;
      b5=s.const_begin();
      e5=s.const_end();
      
  std::cout<<"punto tre " <<std::endl;

  stack<int> s2;
  s2.push(1);

    
  s2.replace( b5, e5);
    std::cout<<"ostream"<<std::endl;
    std::cout<<s<<std::endl;
    std::cout<<s2<<std::endl;

    
}


void test_stack_vuoto(){

  std::cout<<"++++ TEST STACK VUOTO ++++ "<<std::endl;
  stack <int>s;
 
  std::cout<<s.pop()<<std::endl;

   //stack <int>s1=s;
  //stack <int>s2(s);

  //std::cout<<s2.top()<<std::endl;
  //s.pop();



}
void test_vector(){
	typedef std::vector<int> tipo;

	std::cout << "\n***TEST VECTOR***\n" << std::endl;
	std::cout << "Test stack vector vuoto:" << std::endl;
    stack<tipo > sa0;
	std::vector <int> s;
    assert(sa0.get_size() == 0 && "Problema con size, costruttore di default su tipo vector");
    try{
		sa0.push(s);
	} catch(...) {
		std::cout << "Eccezione su inserimento, troppi dati inseriti" << std::endl;
	}
    assert(sa0.get_size() ==1  && "Problema con size, costruttore di default su tipo vector, dopo push");
	std::cout << "OK\n" << std::endl;


	std::cout << "Test stack vector 5/5 elementi:" << std::endl;
	stack<tipo> sa1;
	std::vector<int> s1, s2, s3, s4, s5;
	s1.push_back(5);
	s2.push_back(2);
	s3.push_back(4);
	s4.push_back(3);
	s5.push_back(0);
	sa1.push(s1);
	sa1.push(s2);
	sa1.push(s3);
	sa1.push(s4);
	sa1.push(s5);

	assert(sa1.get_size() == 5 && "Problema con size, costruttore di default su tipo vector");
    std::cout << "OK\n" << std::endl;


	std::cout << "Test stack vector copy constructor:" << std::endl;
  stack <tipo> sa2(sa1);
	stack<tipo > sa3(sa1);

	assert(sa2.get_size() == 5 && "Problema con size, costruttore di default su tipo vector");

	assert(sa2.get_size() == sa3.get_size() && "Problema con size, copy constructor su tipo vector");
	std::cout << "OK\n" << std::endl;


	std::cout << "Test stack vector operator=:" << std::endl;
	sa2=sa1;

	assert(sa2.get_size() == 5 && "Problema con size, operator= su tipo vector");
    std::cout << "OK\n" << std::endl;

  //std::cout<<sa1<<std::endl;

  std::cout<<"Test stack con iteratori di vector"<<std::endl;

  std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(3);
	v1.push_back(0);

  std::vector<int>::const_iterator b, e;
  b=v1.begin();
  e=v1.end();

  stack<int> s_v(b, e);

  	assert(s_v.get_size() == 5 && "Problema con size, costruttore secondario su tipo vector di int");
    std::cout << "OK\n" << std::endl;  

  std::cout<<s_v<<std::endl;

  std::cout<<"Test stack di più vector con iteratori di stack di più vector"<<std::endl;

  stack<tipo> s_v1;
  std::vector<int> v6, v7, v8, v9, v10;
  v6.push_back(7);
  v7.push_back(21);
  v8.push_back(2);
  v9.push_back(9);
  v10.push_back(0);
  s_v1.push(v6);
  s_v1.push(v7);
  s_v1.push(v8);
  s_v1.push(v9);
  s_v1.push(v10);
  stack<tipo>::const_iterator b1, e1;
  b1=s_v1.const_begin();
  e1=s_v1.const_end();

  stack<tipo> s_v2(b1, e1);

  assert(s_v2.get_size() == 5 && "Problema con size, costruttore secondario su tipo vector");
  s_v2.pop();
  assert(s_v2.get_size() == 4 && "Problema con size, pop su tipo vector");

 






	std::cout<<"Test stack vector pulizia:"<<std::endl;
	sa1.empty();
	assert(sa1.get_size() == 0 && "Problema con size, costruttore di default su tipo vector, dopo empty");
	sa1.push(s1);
	assert(sa1.top()[0] == 5 && "Problema con operator() costruttore di default su tipo vector, dopo empty");
	assert(sa1.get_size() != 0 && "Problema con size, costruttore di default su tipo vector, dopo empty");
	std::cout << "OK\n" << std::endl;


	std::cout << "!!!TEST VECTOR PASSATO!!!" <<std::endl;

}

void test_v(){
  typedef std::vector<int> tipo;

	std::cout << "\n***TEST VECTOR***\n" << std::endl;
	std::cout << "Test stack vector vuoto:" << std::endl;
  stack<tipo > sa0;
	std::vector <int> s;
    assert(sa0.get_size() == 0 && "Problema con size, costruttore di default su tipo vector");
    
		sa0.push(s);

  std::cout<<"dimensioni: "<<sa0.get_size()<<std::endl;
}

void test_voce(){

  std::cout<<"++++ TEST STRUCT VOCE ++++ "<<std::endl;
    stack<voce> s_v;
    s_v.push(voce("Palmieri", "Riccardo", 123));
    s_v.push(voce("Pippo", "Pluto", 42));
    s_v.push(voce("Mario", "Rossi", 35));
    s_v.push(voce("Prova3", "Voce", 1235));

    s_v.pop();

    std::cout<<"POP"<<std::endl;

    std::cout<<s_v<<std::endl;

     std::cout<<"REMOVE IF SU PRIMO STACK" << std::endl;
      same_name sn;

      removeIf(s_v, sn);

      std::cout<<s_v<<std::endl;
    std::cout<<"iterator costructor"<<std::endl;
    stack<voce>::const_iterator b, e;
      b=s_v.const_begin();
      e=s_v.const_end();
      
     stack <voce>s_v2(b, e);
     std::cout << s_v2<< std::endl;

     std::cout<<"copy costructor"<<std::endl;

     stack<voce>s3(s_v);

     std::cout<<s3<<std::endl;
      stack<voce>::const_iterator b4, e4;
      b4=s_v.const_begin();
      e4=s_v.const_end();

     s_v2.replace( b4, e4);
    std::cout<<"ostream"<<std::endl;
    std::cout<<s_v2<<std::endl;

     s_v.empty();



      
      
     // std::cout << *b2 << std::endl;

     
    


     



}

void test_stringhe(){

    std::cout<<"++++ TEST STRINGHE ++++"<<std::endl;
    stack<std::string> s;
    s.push("uno");
    s.push("due");
    s.push("tre");
    s.push("quattro");
    s.push("cinque");
    s.push("sei");
    s.push("sette");
    s.push("otto");
    s.push("nove");
    s.push("dieci");
    s.push("undici");
    std::cout<<"numero elementi: " << s.get_size()<< std::endl;
    s.pop();
    std::cout<<"POP"<<std::endl;
    std::cout<<"numero elementi: " << s.get_size()<< std::endl;
    std::cout << s << std::endl;
    
    std::cout<<"in cima ho: " << s.top() << std::endl;
    std::cout<<"iterator"<<std::endl;
    stack<std::string>::const_iterator b, e;
      b=s.const_begin();
      e=s.const_end();

      stack<std::string>s2(b, e);
      
      std::cout << s2 << std::endl;


     
      s2.pop();
      std::cout<<"POP"<<std::endl;
      std::cout<<"in cima ho: " << s2.top() << std::endl;
      string_equals se;

      std::cout<< "REMOVE IF SU PRIMO STACK"<<std::endl;

      removeIf(s, se);

      std::cout<<s<<std::endl;
      stack<std::string>::const_iterator b1, e1;
      b1=s.const_begin();
      e1=s.const_end();
       std::cout<<"replace" <<std::endl;

      s2.replace(b1, e1);
      std::cout<<s2<<std::endl;


     s.empty();


}

void test_iteratore(){
   std::cout<<"++++ TEST MISTO ++++"<<std::endl;

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    stack<int>::const_iterator b, e;
    b=s.const_begin();
    e=s.const_end();
      
    for(; b != e; ++b) {
      std::cout << *b << std::endl;
    }

   std::cout<<"OSTREAM"<<std::endl;

    std::cout<<s<<std::endl;


    stack<std::string> s1;
    s1.push("uno");
    std::cout<<"in cima ho: " << s1.top() << std::endl;
    s1.push("due");
    std::cout<<"in cima ho: " << s1.top() << std::endl;
    s1.push("tre");

    stack<std::string>::const_iterator b1, e1;
    b1=s1.const_begin();
    e1=s1.const_end();
      
    for(; b1 != e1; ++b1) {
      std::cout << *b1 << std::endl;
    }

    std::cout<<"OSTREAM"<<std::endl;

    std::cout<<s1<<std::endl;

    stack<voce> s_v;
    s_v.push(voce("Palmieri", "Riccardo", 123));
    s_v.push(voce("Pippo", "Pluto", 42));
    s_v.push(voce("Mario", "Rossi", 35));
    s_v.push(voce("Prova3", "Voce", 1235));
    

    std::cout<<"iterator"<<std::endl;
    stack<voce>::const_iterator b2, e2;
      b2=s_v.const_begin();
      e2=s_v.const_end();
      
      for(; b2 != e2; ++b2) {
      std::cout << *b2 << std::endl;
      }


    std::cout<<"OSTREAM"<<std::endl;

    std::cout<<s_v<<std::endl;





}

void test_stampa(){

  std::cout<<"++++ TEST STAMPA ++++"<<std::endl;


   stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    std::cout<<s<<std::endl;

    stack<voce> s_v;
    std::cout<<s_v<<std::endl;


     //s.print();
}


void test_complesso(){

  std::cout<<"++++ TEST COMPLESSO ++++"<<std::endl;
  	typedef stack<int> tipo;

  

   tipo s;
    s.push(1);
    s.push(2);
    s.push(3);

  tipo s1;

    s1.push(1);
    s1.push(2);
    s1.push(3);

  
  tipo s2;

    s2.push(1);
    s2.push(2);
    s2.push(3);

  stack<tipo>  ss;

  ss.push(s);
  ss.push(s1);
  ss.push(s2);

 



  
  


  std::cout<<ss<<std::endl;

  ss.pop();

  std::cout<<ss<<std::endl;

  std::cout<<"COPY COSTRUCTOR"<<std::endl;
  stack<stack<int> >sss(ss);
  std::cout<<sss<<std::endl;

   std::cout<<"OPERATOR ="<<std::endl;
  stack<stack<int> >ssss=ss;
  std::cout<<ssss<<std::endl;


 

  
  



}

void test_copia(){
  stack<int> s;
  s.push(1);
  s.push(2);
  s.push(3);

  stack<int> s1(s);
  stack<int> s2=s1;

  std::cout<<"s1: "<< s1 << " s2: "<< s2<<std::endl;

  stack<std::string> st;
    st.push("uno");
    st.push("due");
    st.push("tre");

  stack<std::string> st1(st);
  stack<std::string> st2(st);
   std::cout<<"s1: "<< st1 << " s2: "<< st2<<std::endl;

  
 // s1.print();
  //s2.print();


}




int main(){

  //test_iteratori1();

  
   //
 /*
  // 

  

   

   
  
 

  

    
    */

   test_copia();

   test_replace();

 test_svuotamento();
 test_complesso();
 test_iteratore();
 test_stringhe();
  test_voce();
  //test_stack_vuoto();

  test_vector();
  test_stack_base();
   test_stampa();


  

}