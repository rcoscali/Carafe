/**
 * @file carafe.h
 *
 *   Copyright 2017 R.COHEN-SCALI
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#ifndef __CARAFE_H_
#define __CARAFE_H_

/**
 * Carafe
 *
 * Object modeling a carafe containing a liquid and having 
 * a specific capacity.
 */
class Carafe
{
 public:

  /**
   * Constructor
   *
   * @param capacity the carafe capacity
   */
  Carafe (int);

  /**
   * Filling method
   */
  void remplir (void);

  /**
   * Emptying method
   */
  void vider (void);

  /**
   * Transfering method
   *
   * @param une_carafe The target carafe in which to transfer liquid
   */
  void transvaserDans (Carafe&);

  /**
   * content accessor
   *
   * @return an integer being the actual content quantity in liter
   */
  int contenu (void) const;

  /**
   * capacity accessor
   *
   * @return an integer being the capacity in liter
   */
  int capacite (void) const;

  /**
   * is_empty status
   *
   * @return true is the carafe is empty (content == 0)
   * @return false otherwise
   */
  bool is_empty (void) const;

  /**
   * is_full status
   *
   * @return true if the carafe is full (content == capacity)
   * @return false otherwise
   */
  bool is_full () const;

  /**
   * public index of the carafe
   */
  int m_index;
  
 private:

  // the content in liter
  int m_contenu;

  // the capacity in liter
  int m_capacite;
};

#endif /* __CARAFE_H_ */
