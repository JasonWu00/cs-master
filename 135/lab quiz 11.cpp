//Author: Ze Hong Wu
//Course: CSCI 135
//Instructor: Tong Yi
//Assignment: Lab quiz 11

class Money {
public:
  int dollars;
  int cents;
};

Money add_money(Money x, Money y) {
  Money output = {x.dollars + y.dollars, x.cents + y.cents};
  if (output.cents >= 100) {
    output.dollars += 1;
    output.cents -= 100;
  }
  return output;
}
