#include "Warehouse.h"

using namespace std;

Warehouse::Warehouse() { _pBoxen = new vector<Box *>; }

Warehouse::~Warehouse() {
  for (Box *box : *_pBoxen) {
    delete box;
  }
  _pBoxen->clear();
  delete _pBoxen;
  _pBoxen = nullptr;
}

Warehouse::Warehouse(const Warehouse &WH) {
  _pBoxen = new vector<Box *>;
  for (int i = 0; i < WH.getNumberOfBoxes(); i++) {
    _pBoxen->push_back(new Box(WH.getBox(i)->getBoxSize()));
  }
}

Warehouse &Warehouse::operator=(const Warehouse &WH) {
  for (Box *box : *_pBoxen) {
    delete box;
  }
  _pBoxen->clear();
  delete _pBoxen;
  _pBoxen = new vector<Box *>;
  for (int i = 0; i < WH.getNumberOfBoxes(); i++) {
    _pBoxen->push_back(new Box(WH.getBox(i)->getBoxSize()));
  }
  return *this;
}

void Warehouse::storeInBox(const int SIZE) {
  _pBoxen->push_back(new Box(SIZE));
}

Box *Warehouse::getBox(const int BOX_POS) const { return _pBoxen->at(BOX_POS); }

int Warehouse::getNumberOfBoxes() const { return _pBoxen->size(); }

std::ostream &operator<<(ostream &os, const Warehouse &WH) {
  os << "Warehouse has " << WH.getNumberOfBoxes() << " boxes (";
  for (int i = 0; i < WH.getNumberOfBoxes(); i++) {
    os << WH.getBox(i)->getBoxSize();
    if (i < WH.getNumberOfBoxes() - 1) {
      os << ", ";
    }
  }
  os << ")";
  return os;
}