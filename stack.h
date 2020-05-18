

#ifndef STACK_H
#define STACK_H
#include <algorithm>
#include <iostream>
#include <ostream>
#include <cstddef> // ptrdiff_t
#include <iterator> // categorie degli iterator
#include <functional> 
#include <stdexcept>

/**
@file stack.h 
@brief Dichiarazione della classe stack
**/

/**
@brief stack templato

classe che rappresenta uno stack templato, la dimensione varia dinamicamente**/

template <typename T>
class stack {

private:

		int _size;
		T *_data;
		int _top;
		
		
public:
/**
			@brief Costruttore di default
			Costruttore di default per istanziare uno stack vuoto.
		**/
	stack():_top(-1), _size(0) {
		try{

		_data=new T[_size];
		}catch(...){
			delete[] _data;
		}
	}
  /**
			@brief Metodo per svuotare lo stack, fa la pop() di ogni elemento fino a quando esso non si svuota


			
		**/
	
	void empty(){
		while (!isEmpty()){
			pop();

		}
	}
		/**
			@brief Copy constructor (METODO FONDAMENTALE)

			Costruttore copia. 
			Permette di istanziare uno stack con i valori presi da un altro cbuffer.
			@param other stack da usare per creare quello corrente
			@throw Eccezione dovuta alla tentata allocazione della memoria
		**/

	stack(stack <T> &other){
		
	  if (!other.isEmpty()){
		try{
		this->_data = new T[other._size];
		this->_size=other._size;
		
		this->_top=other._top;
		
   		for(int i = 0; i <_size; i++) {
        _data[i] = other._data[i];
   		}
		}catch(...){
			empty();
			
			delete[] _data;
			throw;
		}

	    std::cout<<"copy costructor"<<std::endl;
	 }else {
		 try{
		 this->_data = new T[0];
		 this->_size =0;
		 this->_top=-1;
		 }catch(...){
			 empty();
			 
			 delete[] _data;
			 throw;
		 }

	 }

	}

	void swap(stack &other){ //funzione privata per scambio dati tra stack
			std::swap(other._size, _size);
			std::swap(other._top, _top);
			std::swap(other._data, _data);
	
		}

/**
			Operatore di assegnamento
		
			@param other stack da copiare
			@return reference a this
			
		*/
	stack &operator=( stack &other){
   	  if(&other != this) {
        stack tmp(other);
		this->swap(tmp);

      }
    
    	return *this;
	}
	/**
			@brief Distruttore (METODO FONDAMENTALE)

			Distruttore. Rimuove la memoria allocata dallo stack.
		**/
	


	~stack() {
    	std::cout << "Freeing memory!" << std::endl;
    	delete[] _data;
		this->_size=0;
		this->_top=-1;
		//this->_count=0;
	}

/**
			Inserisce un elemento in testa allo stack;
			@param value valore da inserire
			@throw eccezione di allocazione di memoria
		*/


	void push(T v) {
		try{
			_top++;
			//_count++;
			
			T *temp = new T[++_size];
			for(int i = 0; i < _top; i++) {
              temp[i] = _data[i];
        	}
			
			delete [] _data;
			_data=temp;
			_data[_top] = v;
			//std::cout<<"inserito dato "<< v << std::endl;
		}catch(...){
			empty();
			delete [] _data;
			throw;
		}
		
			
			
	}

	/**
			rimuove l'elemento in testa allo stack
			
			@throw eccezione di tentativo di prelievo da stack vuoto
			@return boolean che vale false se e solo se la _size del cbuffer è 0
		*/

	T pop() {
		if (isEmpty()){
			throw std::runtime_error("tentativo di prelievo da stack vuoto");
		}
		else {
		T temp = _data[_top];	
		_top--;
		
		_size--;
		T *s=new T[_size];
		for(int i = 0; i < _size; i++) {
              s[i] = _data[i];

        }
		delete [] _data;
		_data=s;
		return temp;
		}	
	}
	/**
			ritorna l'elemento in cima allo stack senza rimuoverlo.

			@throw eccezione di allocazione di memoria
			@return valore in cima allo stack
		*/
	 

	T top() {
		if (isEmpty()){
			std::cout<<"stack vuoto"<<std::endl;
		} else return _data[_top];

	}

	/**
			@brief isEmpty() 

			Metodo per sapere se lo sack è vuoto;
			@return dimensione del cbuffer, _size
		**/
    bool isEmpty() {
		return _top == -1;
	}
	
	/**
			@brief Dimensione dello stack

			Metodo per conoscere la dimensione dello stack
			@return dimensione del cbuffer, _size
		**/
	int get_size(){

		return _size;
	}
	

	

		/**
			Costruttore secondario che costruisce uno stack a partire
			da una sequenza generica di dati identificata da due 
			iteratori.

			
			@param begin iteratore di inizio della sequenza
			@param end iteratore di fine della sequenza

			@throw eccezione di allocazione di memoria
			*/
		

	   template <typename Q>
		stack(Q &begin, Q &end) : _top(-1),_size(0){
			try{
			_data=new T[_size];
				stack<T> tmp;
				Q b=begin;
				Q e=end;
				

		   //stack inserito in modo "ribaltato" 
			for(; begin != end; ++begin) {
				tmp.push(*begin);	
			}
            //stack inserito nella forma originale;
			for(; b != e; ++b){
					push(tmp.pop());
			}



			} catch(...){
				empty();
				delete [] _data;
			}


		}

			/**
			metodo che riempie uno stack a partire
			da una sequenza generica di dati identificata da due 
			iteratori dopo averlo svuotato se questo conteneva elementi in precedenza.

			
			@param begin iteratore di inizio della sequenza
			@param end iteratore di fine della sequenza

			@throw eccezione di allocazione di memoria
			*/


		template< typename Z>
		void replace( Z &begin,  Z &end){
			//stack <T> tmp=s;
		
				if(!isEmpty()){
					empty();
				}

				stack<T> tmp;
				Z b=begin;
				Z e=end;
				
				
				for(; begin !=end; ++begin) {
						tmp.push(*begin);
			   
				}
				for(; b != e; ++b){
					push(tmp.pop());
				}
		
		} 

		
		
		


	

		

		
		


	class const_iterator {
		 
		 const T *s;
		 int p;
		 

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

	
		const_iterator() : s(0), p(0){}
		
		const_iterator(const const_iterator &other) : s(other.s), p(other.p){
			
		
		}

		const_iterator& operator=(const const_iterator &other) {
			s = other.s;
			p = other.p;
			return *this;	
		}

		~const_iterator() {
			s = 0;
			p = 0;
			delete s;
		}

		// Ritorna il dato riferito dall'iteratore (dereferenziamento)
		reference operator*() const {
		  if(p!=-1){
		 
			return s[p];
		  }else return s[-1];
		  
		}

		// Ritorna il puntatore al dato riferito dall'iteratore
		pointer operator->() const {
			if(p!=-1){
		   
			return *s[p];
			}else return *s[-1];
		   

		}
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp(*this);
			p--;
			return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator& operator++() {
			--p;


			return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return ((s == other.s)&&(p==other.p));
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return !(*this == other);
		}


	private:

		friend class stack;

		// Costruttore privato di inizializzazione usato dalla classe container
		// tipicamente nei metodi begin e end
		const_iterator(const T *ss, int pp) : s(ss) {
			this->p=pp;
			
		}
		
	
		
	}; // classe const_iterator


	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator const_begin() const {
		return const_iterator(_data,_top);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator const_end() const {
		return const_iterator(_data, -1);
	}


	



};//classe stack


/**
	@brief Funzione removeIf

Permette di eliminare un elemento dallo stack passato come parametro, se esso rispetta il predicato in input 
	@param s Stack di cui vogliamo eliminare l'elemento
	@param P predicato unario
**/

	

	template <typename T, typename P>
	void removeIf( stack<T> &s, const P &_pred){
		stack<T> tmp;
		while (!s.isEmpty()){
			T elem=s.pop();
			if(!(_pred(elem))){
				tmp.push(elem);
			}else std::cout<<"rimosso "<<elem<< " perche soddisfa il predicato" << std::endl;

		}
		while(!tmp.isEmpty()){		
			s.push(tmp.pop());
		}	
	}

	/**
	@brief Operatore di stream

	Permette di spedire su uno stream di output il contenuto dello stack.

	@param os stream di output
	@param s stack del quale vogliamo stampare il contenuto
	@return Il riferimento allo stream di output
**/

	template <typename T>
std::ostream& operator<<(std::ostream &os, const stack<T> &s) {
    typename stack<T>::const_iterator i, ie;
	i = s.const_begin(), ie = s.const_end();
    for (i ;i != ie; ++i) {
        os << *i << std::endl;
    }
    return os;
}



































#endif 


