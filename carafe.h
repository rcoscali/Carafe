
class Carafe
{
 public:
  Carafe (int capacite);
  void remplir ();
  void vider ();
  void transvaserDans(Carafe&);
  int contenu () const;
  int capacite () const;
 private:
  int m_contenu;
  int m_capacite;
};

