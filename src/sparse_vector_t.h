/**
  * Universidad de La Laguna
  * Escuela Superior de Ingeniería y Tecnología
  * Grado en Ingeniería Informática
  * Informática Básica
  *
  * @file sparse_vector_t.h
  * @author Jose Dorta Luis alu0101414676@ull.edu.es
  * @date 20 March 2021
  * @brief programa proporcionado por el profesorado para realizar la práctica 3 de Algoritmos y estructura de datos
  * @bug ningún bug conocido
  * 
  */
#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

#define EPS 1.0e-6

typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

class sparse_vector_t {
 public:
  // constructores
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&, const double = EPS); // constructor normal
  sparse_vector_t(const sparse_vector_t&);  // constructor de copia

  // operador de asignación
  sparse_vector_t& operator=(const sparse_vector_t&);

  // destructor
  ~sparse_vector_t();
  
  // getters
  int get_nz(void) const;
  int get_n(void) const;

  // getters-setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  
  // getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;

  // E/S
  void write(std::ostream& = std::cout) const;

 private:
  pair_vector_t pv_;  // valores + índices
  int nz_;            // nº de valores distintos de cero = tamaño del vector
  int n_;             // tamaño del vector original

  // bool IsNotZero(const double, const double = EPS) const;
};

/**
 * @brief función que retorna si un determinado valor es 0.
 * @param val valor a comprobar si es 0 o no.
 * @param eps valor mínimo a partir del cual un número se considera 0.
 */
bool IsNotZero(const double val, const double eps = EPS) {
  return fabs(val) > eps;
}

/**
 * @brief constructor por de defecto de la clase sparse_vector_t.
 */
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II
/**
 * @brief constructor de la clase sparse_vector_t
 * @param v vector denso que se va a convertir a un vector disperso.
 * @param eps constante que indica el error que puede permitir un cálculo. 
 */
sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps) : pv_(), nz_(0), n_(0) {
  n_ = v.get_size();
  nz_ = 0;
  
  for (int i{0}; i < v.get_size(); ++i) {
    if (IsNotZero(v[i], eps)) {
      ++nz_;
    }
  pv_.resize(nz_);

  for (int i{0}; i < v.get_size(); ++i) {
    if (IsNotZero(v[i], eps)) {
      pair_double_t pair_stock(v[i], i);
      pv_[i] = pair_stock;
    }
  }
  }

}

/**
 * @brief constructor de copia que inicializa un objeto sparse_vector_t a través de la sobrecarga de operador =.
 * @param w vector del cual se le va a realizar juna copia.
 */
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=
}

/**
 * @brief sobrecarga del operador =.
 * @param w vector del cual se le van a copiar los datos.
 */
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;

  return *this;
}

/**
 * @brief destructor de la clase sparse_vector_t.
 */
sparse_vector_t::~sparse_vector_t() {}

/**
 * @brief getter de la clase sparse_vector_t que retorna el valor del atributo privado nz_
 */
inline int sparse_vector_t::get_nz() const {
  return nz_;
}

/**
 * @brief getter de la clase sparse_vector_t que retorna el valor del atributo privado n_
 */
inline int sparse_vector_t::get_n() const {
  return n_;
}

/**
 * @brief getter-setter de la clase sparse_vector_t que retorna o inicializa el valor de una posición determinada del vector.
 * @param i posición del vector que se desea saber o inicializar su valor
 */
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief sobrecarga del operador [] (permite inializar o conocer un valor del vector dado por su posición)
 * @param i número que indica una posición del vector.
 */
pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}

/**
 * @brief getter de la clase sparse_vector_t que retorna el valor de una posición determinada del vector.
 * @param i posición del vector que se desea saber su valor
 */
const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief sobrecarga constante del operador [] (permite conocer un valor del vector dado por su posición)
 * @param i número que indica una posición del vector.
 */
const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

/**
 * @brief método que permite insertar en el flujo un objeto sparse_vector_t e imprimirlo en pantalla
 */
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

/**
 * @brief sobrecarga del operador de inserción <<.
 * @param sv objeto de la clase sparse_vector_t que será insertado en el flujo.
 */
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
