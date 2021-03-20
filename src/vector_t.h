/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file vector_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 20 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 3 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class vector_t {
 public:
  // constructores
  vector_t(const int = 0);
  vector_t(const vector_t&); // constructor de copia

  // operador de asignación
  vector_t<T>& operator=(const vector_t<T>&);

  // destructor
  ~vector_t();
  
  // getters
  T get_val(const int) const;
  int get_size(void) const;
  
  // setters
  void set_val(const int, const T);
  
  // getters-setters
  T& at(const int);
  T& operator[](const int);
  
  // getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;

  // Redimensionado
  void resize(const int);
  
  // E/S
  void read(std::istream& = std::cin);
  void write(std::ostream& = std::cout) const;

 private:
  T *v_;
  int sz_;
  
  void build(void);
  void destroy(void);
};

/** 
 * @brief constructor de la clase vector_t.
 * @param n tamaño del vector.
 */
template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), sz_(n) {
  build();
}

/**
 * @brief constructor que permite inicializar un objeto de la clase vector_t a partir de copiar otro objeto de la clase vector_t.
 * @param w vector del cual se inicializará uno exactamente identico.
 */
template<class T> vector_t<T>::vector_t(const vector_t<T>& w) : v_(NULL), sz_(0) {
  *this = w; // se invoca directamente al operator=
}

/**
 * @brief sobrecarga del operador = para poder inicializar objetos de la clase vector_t a partir del constructor de copia
 * @param w vector del cual se va a extraer la información para inicializar el nuevo. 
 */
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}

/**
 * @brief destructor de la clase vector_t.
 */
template<class T> vector_t<T>::~vector_t() {
  destroy();
}

/**
 * @brief un método al que llama el contructor para inicializar un objeto vector_t.
 */
template<class T> void vector_t<T>::build() {
  v_ = NULL;
  if (sz_ != 0) {
    v_ = new T[sz_];
    assert(v_ != NULL);
  }
}

/**
 * @brief un método al que llama el destructor para destruir los residuos que pueda dejar este objeto.
 */
template<class T> void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  sz_ = 0;
}

/**
 * @brief método que permite cambiar el tamaño del vector y a su vez reservar la memoria necesaria.
 * @param n tamaño del nuevo vector.
 */
template<class T> void vector_t<T>::resize(const int n) {
  destroy();
  sz_ = n;
  build();
}

/**
 * @brief método que permite conocer el valor de una posición prederteminada del vector. (getter)
 * @param i posición del vector cuyo valor se quiere conocer.
 */
template<class T> inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief método que retorna el tamaño del vector.
 */
template<class T> inline int vector_t<T>::get_size() const {
  return sz_;
}

/**
 * @brief permite dale un valor predeterminado a una posición determinada del vector.
 * @param i posición del vector a la que se le quiere dar valor.
 * @param d nuevo valor que a tener la posición i del vector.
 */
template<class T> void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}

/**
 * @brief getter-setter de la clase vector_t.
 * @param i posición del vector que se quiere conocer o sobreescribir.
 */
template<class T> T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief sobrecarga del operador []
 * @param i posición del vector
 */
template<class T> T& vector_t<T>::operator[](const int i) {
  return at(i);
}

/**
 * @brief getter constante  de la clase vector_t.
 * @param i posición del vector que se quiere conocer.
 */
template<class T> const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}

/**
 * @brief sobrecarga constante del operador []
 * @param i posición del vector
 */
template<class T> const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}

/**
 * @brief permite leer e inicializar un objeto vector_t a partir de una secuencia de caracteres.
 */
template<class T> void vector_t<T>::read(std::istream& is) {
  is >> sz_;
  resize(sz_);
  for (int i = 0; i < sz_; i++)
    is >> at(i);
}

/**
 * @brief permite imprimir en pantalla un objeto de la clase vector_t.
 */
template<class T> void vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}

/**
 * @brief sobrecarga del operador de extracción >>
 * @param v vector que donde se almacenará la infromación que se extraiga
 */
template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) {
  v.read(is);
  return is;
}

/**
 * @brief sobrecarga del operador de inserción <<
 * @param v vector que se insertará en el flujo
 */
template<class T> std::ostream& operator<<(std::ostream& os, const vector_t<T>& v) {
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
