
class Carafe
{
 public:
  Carafe (int capacite);
  void remplir ();
  void vider ();
  void transvaserDans(Carafe&);
  int contenu () const;
  int capacite () const;
  bool is_empty() const;
  bool is_full() const;
  int m_index;
 private:
  int m_contenu;
  int m_capacite;
};

