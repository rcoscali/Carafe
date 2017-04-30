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

Carafe::Carafe(int capacite)
  : m_capacite(capacite),
    m_contenu(0)
{
}

void
Carafe::remplir(void)
{
  if (is_full())
    std::cerr << "Warning ! This carafe is already full !\n";

  else
    m_contenu = m_capacite;
}

void
Carafe::vider(void)
{
  if (is_empty())
    std::cerr << "Warning ! This carafe is already empty !\n";

  else
    m_contenu = 0;
}

void
Carafe::transvaserDans(Carafe &une_carafe)
{
  if (is_empty())
    std::cerr << "Warning ! The source carafe is empty !\n";

  else if (une_carafe.is_full())
    std::cerr << "Warning ! The target carafe is full !\n";

  else
    {
      int dispo = une_carafe.capacite() - une_carafe.contenu();
      if (m_contenu > dispo)
        {
          une_carafe.remplir();
          m_contenu -= dispo;
        }
      else
        {
          une_carafe.m_contenu = une_carafe.contenu() + m_contenu;
          m_contenu = 0;
        }
    }
}

int
Carafe::contenu() const
{
  return m_contenu;
}

int
Carafe::capacite() const
{
  return m_capacite;
}

bool
Carafe::is_empty() const
{
  return (m_contenu == 0);
}

bool
Carafe::is_full() const
{
  return (m_contenu == m_capacite);
}
