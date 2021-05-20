class WaterLevel{
private:
  int* levels;
  int size;
public:
  WaterLevel(int *array, int size);
  ~WaterLevel()
  int high(int threshold);
}

WaterLevel::WaterLevel(int *array, int size) {
  if (size < 0) {
    this->size = 3;
    this->levels = new int[size];
    this->levels[0] = 10;
    this->levels[1] = 25;
    this->levels[2] = 36;
  }

  else {
    this->size = size;
    this->levels = new int[size];
    for (int i = 0; i < size; i++) {
      this->levels[i] = array[i];
    }
  }
}

Waterlevel::~Waterlevel() {
  delete[] levels;
  levels = 0;
}

int Waterlevel::high(int threshold) {
  int output = 0;
  for (int i = 0; i < this->size; i++) {
    if (this->levels[i] > threshold) {
      output++;
    }
  }
  return output;
}
