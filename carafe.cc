/**
 * @file carafe.cc
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
#include <iostream>

#include "carafe.h"

// Constructor
Carafe::Carafe (int capacite)
  : m_capacite (capacite),
    m_contenu (0)
{
  // nothing to do
}

// Remplir method
void
Carafe::remplir (void)
{
  // If carafe already full,
  if (is_full ())
    // Issue warning
    std::cerr << "Warning ! This carafe is already full !\n";

  else
    // Else make it full
    m_contenu = m_capacite;
}

// Vider method
void
Carafe::vider (void)
{
  // If carafe is empty,
  if (is_empty ())
    // Issue warning
    std::cerr << "Warning ! This carafe is already empty !\n";

  else
    // Else make it empty
    m_contenu = 0;
}

// TransvaserDans method
void
Carafe::transvaserDans (Carafe &une_carafe)
{
  // If source carafe is empty
  if (is_empty ())
    // Issue warning
    std::cerr << "Warning ! The source carafe is empty !\n";

  // Else if target carafe is full
  else if (une_carafe.is_full ())
    // Issue warning
    std::cerr << "Warning ! The target carafe is full !\n";

  // Else
  else
    {
      // Get quantity available in target carafe
      int dispo = une_carafe.capacite () - une_carafe.contenu ();
      // If quantity to transfer is higher that available quantity
      if (m_contenu > dispo)
        {
          // Fill the target carafe
          une_carafe.remplir ();
          // Remove the delta quantity from the source carafe
          m_contenu -= dispo;
        }
      else
        {
          // Compute the new quantity in target carafe
          une_carafe.m_contenu = une_carafe.contenu () + m_contenu;
          // Empty the source one
          m_contenu = 0;
        }
    }
}

// content accessor
int
Carafe::contenu () const
{
  return m_contenu;
}

// capacity accesor
int
Carafe::capacite () const
{
  return m_capacite;
}

bool
Carafe::is_empty () const
{
  return (m_contenu == 0);
}

bool
Carafe::is_full () const
{
  return (m_contenu == m_capacite);
}
