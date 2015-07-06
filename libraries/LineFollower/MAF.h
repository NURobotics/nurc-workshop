#ifndef MAF_H_
#define MAF_H_

#define MAF_SIZE 5

class MAF {
public:
  MAF() { reset(); }
  double value() const;
  double filter(int input);
  void reset();
private:
  int head;
  bool initialized;
  int data[MAF_SIZE];
};

#endif // MAF_H_
