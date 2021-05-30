#include "UnionFindAgency.h"
#include "CarType.h"

#define N 50

UnionFindAgency::UnionFindAgency():car_agencies(new CarAgency*[N * sizeof(CarAgency*)]) , max_size(N), curr_size(0) {
    for(int i = 0; i < N; i++){
        car_agencies[i] = NULL;
    }
}

UnionFindAgency::~UnionFindAgency(){
    for(int i = 0; i < curr_size; i++){
        car_agencies[i]->types_tree.empty();
        delete car_agencies[i];
    }
    delete [] car_agencies;
}

UnionFindAgency::CarAgency::CarAgency(int agency_id): agency_id(agency_id), tree_size(1), father(NULL), types_tree(){}

void UnionFindAgency::AddCarAgency() {
    if (curr_size == max_size) { //no more place in array so make it bigger
        max_size *= 2;
        CarAgency **new_car_agencies = new CarAgency *[max_size * sizeof(CarAgency*)];
        for (int i = 0; i < max_size; i++) {
            new_car_agencies[i] = NULL;
            if (curr_size < i) {
                new_car_agencies[i] = car_agencies[i];
            }
        }
        delete[] car_agencies;
        car_agencies = new_car_agencies;
    }

    CarAgency *new_car_agency = new CarAgency(curr_size);
    car_agencies[curr_size] = new_car_agency;
    curr_size++;
}

UnionFindAgency::CarAgency* UnionFindAgency::FindCarAgency(int agency){
    if(car_agencies[agency] == NULL) {
        throw AgencyDoesntExists();
    }
    return findAux(car_agencies[agency]);
}

UnionFindAgency::CarAgency* UnionFindAgency::findAux(CarAgency* agency) {
    if(agency->father == NULL) {
        return agency;
    }
    CarAgency* root = findAux(agency->father);
    agency->father = root;
    return root;
}

void UnionFindAgency::SellCar(int agency_id, int sales, int type_id) {
    CarAgency* car_agency = FindCarAgency(agency_id);
    CarType *car_type;
    try {
        car_type = car_agency->types_tree.find(CarType(type_id, 0));
    } catch (NodeDoesntExist &e){
        car_agency->types_tree.insert(CarType(type_id, sales)); //new car in agency
        return;
    }
    //updating car sales in agency
    car_agency->types_tree.remove(CarType(type_id, 0));
    int updated_sells = sales + car_type->getSales();
    car_agency->types_tree.insert(CarType(type_id, updated_sells));
}

void UnionFindAgency::UniteCarAgencies(int agency_1, int agency_2){
    CarAgency* car_agency1 = FindCarAgency(agency_1);
    CarAgency* car_agency2 = FindCarAgency(agency_2);

    //merging both trees to array
    AVLTree<CarType>::AvlIterator agency_it1 = car_agency1->types_tree.begin();
    AVLTree<CarType>::AvlIterator agency_it2 = car_agency2->types_tree.begin();
    int i = 0, new_tree_size = car_agency1->tree_size + car_agency2->tree_size;
    CarType* arr_tree_unite = new CarType[new_tree_size * sizeof(CarType)];
    while(agency_it1!= car_agency1->types_tree.end() && agency_it2!= car_agency2->types_tree.end()){
        if(*agency_it1 < *agency_it2){
            arr_tree_unite[i] = *(*agency_it1);
            ++agency_it1;
        }
        else{
            arr_tree_unite[i] = *(*agency_it2);
            ++agency_it2;
        }
        i++;
    }
    while(agency_it1!= car_agency1->types_tree.end()){
        arr_tree_unite[i] = *(*agency_it1);
        ++agency_it1;
        i++;
    }
    while(agency_it2!= car_agency2->types_tree.end()){
        arr_tree_unite[i] = *(*agency_it2);
        ++agency_it2;
        i++;
    }

    car_agency1->types_tree.empty();
    car_agency2->types_tree.empty();

    //uniting agencies by agency size
    if(car_agency1->tree_size > car_agency2->tree_size){
        car_agency2->father = car_agency1;
        car_agency1->types_tree.sortedArrayInit(arr_tree_unite, new_tree_size);
        car_agency1->tree_size = new_tree_size;
    }else{
        car_agency1->father = car_agency2;
        car_agency2->types_tree.sortedArrayInit(arr_tree_unite, new_tree_size);
        car_agency1->tree_size = new_tree_size;
    }
    delete [] arr_tree_unite;
}

int UnionFindAgency::GetIthSoldType(int agency_id, int i){
    CarAgency* car_agency = FindCarAgency(agency_id);
    CarType* car_to_select = car_agency->types_tree.select(i);
    return car_to_select->getTypeId();
}