#include "carafe.h"

Carafe::Carafe(int capacite)
  : m_capacite(capacite),
    m_contenu(0)
{
}

void
Carafe::remplir(void)
{
  m_contenu = m_capacite;
}

void
Carafe::vider(void)
{
  m_contenu = 0;
}

void
Carafe::transvaserDans(Carafe &une_carafe)
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
