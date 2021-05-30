#ifndef DS_HW2_CAR_TYPE_H
#define DS_HW2_CAR_TYPE_H

class CarType {
private:
    int type_id;
    int sales;
public:
    CarType(int typeId = -1, int sales = -1);
    ~CarType() = default;
    CarType(const CarType&);
    CarType& operator=(const CarType&);
    bool operator<(const CarType&) const;
    bool operator==(const CarType&) const;
    int getSales() const;
    int getTypeId() const;
};

bool operator>(const CarType& car_type1, const CarType& car_type2);

#endif //DS_HW1_CAR_BEST_SELLS_H
