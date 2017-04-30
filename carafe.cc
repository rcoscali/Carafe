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
