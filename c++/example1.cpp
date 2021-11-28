#include <stdio.h>
struct str_complex {
  private:
    double re, im, mod, arg;
  public:
    str_complex(double a_re, double a_im) {
      re = a_re; im = a_im;
      mod = sqrt(re*re + im*im);
      arg = atan2(im, re);
    }
    double get_re() { return re; }
    double get_im() { return im; }
    double modulo() { return mod; }
    double argument() { return arg; }
};

int main()
{
  str_complex z(2.7, 3.8);
  double mod;
  mod = z.modulo();
  printf("%f\n", mod);
  return 0;
}
