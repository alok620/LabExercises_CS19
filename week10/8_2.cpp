#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;

//Class for amounts of money in U.S. currency.
class Money
{
public:
  Money( );
  Money(double amount);
  Money(int theDollars, int theCents);
  Money(int theDollars);
  double getAmount( ) const;
  int getDollars( ) const;
  int getCents( ) const;
  const Money percent(int percentFigure) const;
  friend const Money operator +(const Money& amount1, const Money& amount2);
  friend const Money operator -(const Money& amount1, const Money& amount2);
  friend bool operator ==(const Money& amount1, const Money& amount2);
  friend const Money operator -(const Money& amount);
  friend ostream& operator <<(ostream& outputStream, const Money& amount);
  friend istream& operator >>(istream& inputStream, Money& amount);
  friend bool operator <(const Money& amount1, const Money& amount2);
  friend bool operator >(const Money& amount1, const Money& amount2);
  friend bool operator <=(const Money& amount1, const Money& amount2);
  friend bool operator >=(const Money& amount1, const Money& amount2);
private:
  int dollars; //A negative amount is represented as negative dollars and
  int cents; //negative cents. Negative $4.50 is represented as -4 and -50

  int dollarsPart(double amount) const;
  int centsPart(double amount) const;
  int round(double number) const;
};

int main( )
{
  Money yourAmount, myAmount(10, 9);
  cout << "Enter an amount of money: ";
  cin >> yourAmount;
  cout << "Your amount is " << yourAmount << endl;
  cout << "My amount is " << myAmount << endl;

  if (yourAmount == myAmount)
    cout << "We have the same amounts.\n";
  else
    cout << "One of us is richer...\n";

  if(yourAmount > myAmount){
    cout << "And it's you *sigh*\n";
  } else {
    cout << "And it's ME, HA.\n";
  }

  Money ourAmount = yourAmount + myAmount;
  cout << yourAmount << " + " << myAmount
       << " equals " << ourAmount << endl;

  Money diffAmount = yourAmount - myAmount;
  cout << yourAmount << " - " << myAmount
       << " equals " << diffAmount << endl;
  std::cout << ourAmount << ": " << ourAmount.percent(10) << "\n";

  return 0;
}

ostream& operator <<(ostream& outputStream, const Money& amount)
{
  int absDollars = abs(amount.dollars);
  int absCents = abs(amount.cents);
  if (amount.dollars < 0 || amount.cents < 0)
    //accounts for dollars == 0 or cents == 0
    outputStream << "$-";
  else
    outputStream << '$';
  outputStream << absDollars;

  if (absCents >= 10)
    outputStream << '.' << absCents;
  else
    outputStream << '.' << '0' << absCents;

  return outputStream;
}

//Uses iostream and cstdlib:
istream& operator >>(istream& inputStream, Money& amount)
{
  char dollarSign;
  inputStream >> dollarSign; //hopefully
  if (dollarSign != '$')
    {
      cout << "No dollar sign in Money input.\n";
      exit(1);
    }


  double amountAsDouble;
  inputStream >> amountAsDouble;
  amount.dollars = amount.dollarsPart(amountAsDouble);
  amount.cents = amount.centsPart(amountAsDouble);


  return inputStream;
}

const Money operator +(const Money& amount1, const Money& amount2)
{
  int allCents1 = amount1.cents + amount1.dollars*100;
  int allCents2 = amount2.cents + amount2.dollars*100;
  int sumAllCents = allCents1 + allCents2;
  int absAllCents = abs(sumAllCents); //Money can be negative.
  int finalDollars = absAllCents/100;
  int finalCents = absAllCents%100;

  if (sumAllCents < 0)
    {
      finalDollars = -finalDollars;
      finalCents = -finalCents;
    }

  return Money(finalDollars, finalCents);
}

//Uses cstdlib:
const Money operator -(const Money& amount1, const Money& amount2)
{
  int allCents1 = amount1.cents + amount1.dollars*100;
  int allCents2 = amount2.cents + amount2.dollars*100;
  int diffAllCents = allCents1 - allCents2;
  int absAllCents = abs(diffAllCents);

  int finalDollars = absAllCents/100;
  int finalCents = absAllCents%100;

  if (diffAllCents < 0)
    {
      finalDollars = -finalDollars;
      finalCents = -finalCents;
    }

  return Money(finalDollars, finalCents);
}

bool operator ==(const Money& amount1, const Money& amount2)
{
  return ((amount1.dollars == amount2.dollars)
          && (amount1.cents == amount2.cents));
}

const Money operator -(const Money& amount)
{
  return Money(-amount.dollars, -amount.cents);
}


Money::Money( ): dollars(0), cents(0)
{/*Body intentionally empty.*/}

Money::Money(double amount)
  : dollars(dollarsPart(amount)), cents(centsPart(amount))
{/*Body intentionally empty*/}

Money::Money(int theDollars)
  : dollars(theDollars), cents(0)
{/*Body intentionally empty*/}

//Uses cstdlib:
Money::Money(int theDollars, int theCents)
{
  if ((theDollars < 0 && theCents > 0) || (theDollars > 0 && theCents < 0))
    {
      cout << "Inconsistent money data.\n";
      exit(1);
    }
  dollars = theDollars;
  cents = theCents;
}

double Money::getAmount( ) const
{
  return (dollars + cents*0.01);
}

int Money::getDollars( ) const
{
  return dollars;
}

int Money::getCents( ) const
{
  return cents;
}

int Money::dollarsPart(double amount) const
{
  return static_cast<int>(amount);
}

int Money::centsPart(double amount) const
{
  double doubleCents = amount*100;
  int intCents = (round(fabs(doubleCents)))%100;//% can misbehave on negatives
  if (amount < 0)
    intCents = -intCents;
  return intCents;
}

int Money::round(double number) const
{
  return static_cast<int>(floor(number + 0.5));
}

bool operator <(const Money& amount1, const Money& amount2){
  return ((amount1.dollars < amount2.dollars) || ((amount1.dollars == amount2.dollars) && (amount1.cents < amount2.cents)));
}

bool operator >(const Money& amount1, const Money& amount2){
  return ((amount1.dollars > amount2.dollars) || ((amount1.dollars == amount2.dollars) && (amount1.cents > amount2.cents)));
}

bool operator <=(const Money& amount1, const Money& amount2){
  return ((amount1.dollars <= amount2.dollars) || ((amount1.dollars == amount2.dollars) && (amount1.cents <= amount2.cents)));
}

bool operator >=(const Money& amount1, const Money& amount2){
 ((amount1.dollars >= amount2.dollars) || ((amount1.dollars == amount2.dollars) && (amount1.cents >= amount2.cents)));
}

const Money Money::percent(int percentFigure) const{
  int d = dollars * percentFigure/100;
  int c = dollars * percentFigure % 100 + cents * percentFigure / 100;
  return Money(d, c);
}
[ashah@pengo week09]$ clear
[ashah@pengo week09]$ ls
#8_1.cpp#  8_1.cpp  8_1.cpp~  8_2.cpp  8_2.cpp~  a.out
[ashah@pengo week09]$ cd 8_2.cpp
-bash: cd: 8_2.cpp: Not a directory
[ashah@pengo week09]$ cat 8_2.cpp
#include <iostream>
#include <cmath>
#include <cstdlib>

using std::cout;
using std::endl;
using std::cin;

class Rational{
public:
  Rational(int nNumerator, int nDenominator) {
    numerator = nNumerator; denominator = nDenominator;
    normalize();
  }
  Rational(int wholeNumber) {numerator = wholeNumber; denominator = 1;}
  Rational() {numerator = 0; denominator = 1;}
  void normalize();
  int gcd();
  friend std::ostream& operator <<(std::ostream &os, const Rational &);
  friend std::istream& operator >>(std::istream &is, Rational &);
  friend Rational operator +(const Rational &, const Rational &);
  friend Rational operator -(const Rational &, const Rational &);
  friend Rational operator *(const Rational &, const Rational &);
  friend Rational operator /(const Rational &, const Rational &);
  friend bool operator <(const Rational &, const Rational &);
  friend bool operator >(const Rational &, const Rational &);
  friend bool operator <=(const Rational &, const Rational &);
  friend bool operator >=(const Rational &, const Rational &);
  friend bool operator ==(const Rational &, const Rational &);
private:
  int numerator;
  int denominator;
};

int Rational::gcd(){
  int temp;
  int n = abs(numerator);
  int d = abs(denominator);
  if(d < n){
    temp = d;
    d = n;
    n = temp;
  }
  int remainder = n % d;
  while(remainder != 0){
    remainder = n % d;
    n = d;
    d = remainder;
  }
  return n;
}

void Rational::normalize(){
  int g = gcd();
  numerator /= g;
  denominator /= g;

  if(numerator > 0 && denominator < 0 || numerator < 0 && denominator < 0){
    numerator = -numerator;
    denominator = -denominator;
  }
}

std::ostream& operator <<(std::ostream &os, const Rational &r){
  os << r.numerator << "/" << r.denominator;
  return os;
}

std::istream& operator >>(std::istream &is, Rational &r){
  char c;
  is >> r.numerator >> c >> r.denominator;
  if(c != '/'){
    std::cout << "bad input format for >>. exiting\n";
    exit(1);
  }
  r.normalize();
  return is;
}

Rational operator +(const Rational &left, const Rational &right){
  int n = left.numerator * right.denominator + left.denominator * right.numerator;
  int d = left.denominator * right.denominator;
  Rational r(n, d);
  r.normalize();
  return r;
}

Rational operator -(const Rational &left, const Rational &right){
  int n = left.numerator * right.denominator - left.denominator * right.numerator;
  int d = left.denominator * right.denominator;
  Rational r(n, d);
  r.normalize();
  return r;
}

Rational operator *(const Rational &left, const Rational &right){
  int n = left.numerator * right.numerator;
  int d = left.denominator * right.denominator;
  Rational product(n, d);
  product.normalize();
  return product;
}

Rational operator /(const Rational &left, const Rational &right){
  int n = left.numerator * right.denominator;
  int d = left.denominator * right.numerator;
  Rational quotient(n, d);
  quotient.normalize();
  return quotient;
}

bool operator <(const Rational &left, const Rational &right){
  return left.numerator * right.denominator < left.denominator * right.numerator;
}

bool operator >(const Rational &left, const Rational &right){
  return left.numerator * right.denominator > left.denominator * right.numerator;
}

bool operator <=(const Rational &left, const Rational &right){
  return left.numerator * right.denominator <= left.denominator * right.numerator;
}

bool operator >=(const Rational &left, const Rational &right){
  return left.numerator * right.denominator >= left.denominator * right.numerator;
}

bool operator ==(const Rational &left, const Rational &right){
  return left.numerator * right.denominator == left.denominator * right.numerator;
}