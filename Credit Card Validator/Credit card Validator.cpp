#include<iostream>
#include <array>
#include <cmath>
#include <string>

using namespace std;

void cardbreakup(long card_number, int card_len, int card_bits[19]){
  if(card_len >= 13){
    for(int i=0; i<card_len; i++){
      int digit =  card_number % 10;
      card_number /= 10;
      card_bits[i] = digit;
    }
  }
  else{
    cout << "Card number is too short\n";
  }
}

bool validate_card(int card_bits[19], int card_len){
  int sum1=0, sum2=0;
  bool card_is_valid=false;

  for(int j=1; j<card_len; j+=2){
    card_bits[j] *= 2;
    if (card_bits[j] > 9){
			int c = card_bits[j] % 10;
			int d = card_bits[j] /= 10;
			card_bits[j] = c + d;
		}
		sum1 += card_bits[j];
  }

  for (int k=0; k<card_len; k+=2){
		sum2 += card_bits[k];
	}
  
	sum1 += sum2;
	sum1 %= 10;
  
	if (sum1 == 0){
		card_is_valid = 1;
	}

  return card_is_valid;
}

string card_type(int card_len, int card_bits[19]){
  string c_type="";
  
  if (card_bits[card_len - 1] == 4){
		c_type = "Visa Card";
	}
	else if ((card_bits[card_len - 1] == 3) && (card_bits[card_len - 2] == 7)){
		c_type = "American Express";
	}
	else if (card_bits[card_len - 1] == 5){
		c_type = "Master Card";
	}
	else if (card_bits[card_len - 1] == 6){
		c_type = "Discover Card";
	}
  return c_type;
}

int main(){
  long creditcard;
  cout << "Enter Card Number\n";
  cin >> creditcard;
  string type="";
  bool valid;
  int cardbits[19];
  int card_copy[19];
  int card_length = log10(creditcard) + 1;

  cardbreakup(creditcard, card_length, cardbits);
  cardbreakup(creditcard, card_length, card_copy);
  valid = validate_card(cardbits, card_length);
  type = card_type(card_length, card_copy);

  if(valid){
    cout << "Card Type: " << type << " | Card number: " << creditcard << " is valid\n";
  }
  else{
    cout << "Card number " << creditcard << " is not valid\n";
  }

  return 0;
}