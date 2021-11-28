#include <stdio.h>

class Pointer_s1 {
  s1 *p;
public:
  Pointer_s1(s1 *ptr = 0) : p(ptr) {}
  ~Pointer_s1() { if(p) delete p;}
  s1* operator=(s1 *ptr) {
    if(p)
      delete p;
    p = ptr;
    return p;
  }
  s1& operator*() const { return *p; }
  s1* operator->() const { return p;  }
private:
  Pointer_s1(const Pointer_s1&) {} // no copying
  void operator=(const Pointer_s1&) {} // no assigments
};

int f()
{
  Pointer_s1 p;
  p = new s1;
  p->a = 25;
  p->b = p->a + 36;
}

int main()
{

  return 0;
}
