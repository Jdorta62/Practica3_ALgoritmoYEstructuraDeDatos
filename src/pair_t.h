/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file pair_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 20 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 3 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> class pair_t {
 public:
  // constructores
  pair_t(void); 
  pair_t(T, int);

  // destructor
  ~pair_t(void);

  // getters & setters
  T get_val(void) const;
  int get_inx(void) const;
  void set(T, int);

  // E/S
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  T val_;
  int inx_;
};

/**
 * @brief constructor en el caso de que no se pase ningun parámetro, es decir, cuando todos los elementos del vector son 0. 
 */
template<class T> pair_t<T>::pair_t() : val_(), inx_(-1) {}

/**
 * @brief constructor en el caso de que algun elemnto del vector sea distinto de 0.
 */
template<class T> pair_t<T>::pair_t(T val, int inx) : val_(val), inx_(inx) {}

/**
 * @brief destructor de la clase pair_t.
 */
template<class T> pair_t<T>::~pair_t() {}

/**
 * @brief setter de la clase pair_T. Permite inicializar los atributos privados.
 */
template<class T> void pair_t<T>::set(T val, int inx) {
  val_ = val;
  inx_ = inx;
}

/**
 * @brief getter de la clase pair_T para obtener el valor del atributo privado inx_.
 */
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

/**
 * @brief getter de la clase pair_T para obtener el valor del atributo privado inx_.
 */
template<class T> T pair_t<T>::get_val() const {
  return val_;
}

/**
 * @brief método que permite extraer e inicializar un objeto de la clase pair_t.
 */
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> val_;
}

/**
 * @brief método que permite insertar en el flujo un objeto de la clase pair_t.
 */
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << val_ << ")";
}

/**
 * @brief sobrecarga del operacor de inserción << que permite insertar en el flujo un objeto pair_t.
 */
template<class T> std::ostream& operator<<(std::ostream& os, const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
