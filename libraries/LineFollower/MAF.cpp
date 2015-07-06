#include <MAF.h>

void MAF::reset() {
  head = 0;
  initialized = false;
  memset(data, MAF_SIZE, 0); 
}

double MAF::filter(int input) {
  data[head] = input;
  head = (head+1) % MAF_SIZE;
  if(!initialized && head == 0)
    initialized = true;
  return value();
}

double MAF::value() const {
  int sum = 0;
  if(!initialized && head != 0) {
    for(int i = 0; i < head; i++) sum += data[i];
    return double(sum) / head;
  } else {
    for(int i = 0; i < MAF_SIZE; i++) sum += data[i];
    return double(sum) / MAF_SIZE;
  }
}
