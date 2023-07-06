/**
 * @file classes_implementation.cpp
 * 
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * 
 * @brief Este file define los metodos de las clases
 * 
 * @date 2023-04-19
 * 
 * @copyright MIT
 * 
 */

#include "libraries.hpp"
#include "classes_structure.hpp"
#include "functions_structure.hpp"

/**
 *  @brief En este archivo hay cuatro tipos de clases: constructor(Iniciar valores al crear la clase),set(inicializar variables), get(obtener el valor de la variable), print(Imprimir los datos de la clase)
 * 
 */

//Campus implementation
void Campus::set_property_names(string property){
    property_names.push_back(property);
}
void Campus::set_campus_name(string campus_name){
    this->campus_name = campus_name;
}

/**
 * @brief Imprime las fincas del campus se usa un for para iterar sobre el vector
 * 
 */
void Campus::print_campus(){
    cout << "Nombre del campus: " << this->campus_name;
    cout << ", posee " << this->get_number_of_properties()<< " Fincas:";
    for(int i = 0; i < properties.size(); i++){
        cout<<" - "<<properties[i].get_property_name();
    }
    cout<<endl;
}
short unsigned int Campus::get_number_of_properties(){
    return properties.size();
}
vector<string> Campus::get_property_names(){
    return this->property_names;
}
string Campus::get_campus_name(){
    return this->campus_name;
}
short unsigned int Campus::get_classroom_id(){
    return this->_classroom_id;
}
void Campus::set_classroom_id(short unsigned int _classroom_id){
    this->_classroom_id = _classroom_id;
}

//Property implementation
string Property::get_property_name(){
    return this->property_name;
}
bool Property::get_bus(){
    return this->bus;
}
void Property::set_bus(bool bus){
    this->bus = bus;
}
void Property::set_property_name(string property_name){
    this->property_name = property_name;
    set_property_names(property_name);
}
void Property::print_bus_location(){
    if (this->bus==true){
        cout <<"- "<<get_property_name()<<" ";
    }
}
short unsigned int Property::get_number_of_parking_buildings(){
    return this->parking_buildings.size();
}
short unsigned int Property::get_number_of_classroom_buildings(){
    return this->classroom_buildings.size();
}
short unsigned int Property::get_total_number_of_buildings(){
    return (this->parking_buildings.size() + this->classroom_buildings.size());
}

//Building implementation
void Building::set_elevator(bool elevator){
    this->elevator = elevator;
}
void Building::set_building_name(string building_name){
    this->building_name = building_name;
}
void Building::set_number_of_floors(short unsigned int number_of_floors){
    this->number_of_floors = number_of_floors;
}
bool Building::get_elevator(){
    return this->elevator;
}
string Building::get_building_name(){
    return this->building_name;
}
short unsigned int Building::get_number_of_floors(){
    return this->number_of_floors;
}

//ParkingBuilding implementation
void ParkingBuilding::set_number_of_parking_spots(short unsigned int number_of_parking_spots) {
    this->number_of_parking_spots = number_of_parking_spots;
}
void ParkingBuilding::set_number_of_washrooms(short unsigned int number_of_washrooms) {
    this->number_of_washrooms = number_of_washrooms;
}
short unsigned int ParkingBuilding::get_number_of_parking_spots(){
    return this->number_of_parking_spots;
}
short unsigned int ParkingBuilding::get_number_of_washrooms() {
    return this->number_of_washrooms;
}
void ParkingBuilding::print_parking_info(){

    cout<<get_building_name()<<(get_elevator()?" tiene":" no tiene")<<" elevadores, "<<get_number_of_floors()<<" pisos, "<<get_number_of_parking_spots()<<" campos de parqueo y "<<get_number_of_washrooms()<<" banios."<<endl;
}

//ClassroomBuilding implementation
void ClassRoomBuilding::set_cafeteria(bool cafeteria){
    this->cafeteria = cafeteria;
}
void ClassRoomBuilding::set_auditorium(bool auditorium) {
    this->auditorium = auditorium;
}
bool ClassRoomBuilding::get_cafeteria(){
    return this->cafeteria;
}
bool ClassRoomBuilding::get_auditorium(){
    return this->auditorium;
}
short unsigned int ClassRoomBuilding::total_classrooms(){
    return this->classroom.size();
}
void ClassRoomBuilding::print_classroom_building_info(){
    cout<<get_building_name()<<(get_elevator()?" tiene":" no tiene")<<" elevadores, "<<get_number_of_floors()<<" pisos, "<<(get_cafeteria()?"tiene":"no tiene")<<" cafeterias, "<<(get_auditorium()?"tiene":"no tiene")<<" auditorios y "<<total_classrooms()<<" aulas."<<endl;
}

//ClassRoom implementation
ClassRoom::ClassRoom():__id(0),number_of_desks(0),projector(false),floor(0) {
    this->__id = get_classroom_id();
    set_classroom_id(get_classroom_id()+1);
};
ClassRoom::ClassRoom(short unsigned int number_of_desks, bool projector, short unsigned int floor):__id(0),number_of_desks(number_of_desks),projector(projector),floor(floor){
    this->__id = get_classroom_id();
    set_classroom_id(get_classroom_id()+1);
};
void ClassRoom::set__id(short unsigned int __id){
    this->__id = __id;
}
void ClassRoom::set_number_of_desks(short unsigned int number_of_desks){
    this->number_of_desks = number_of_desks;
}
void ClassRoom::set_projector(bool projector){
    this->projector = projector;
}
void ClassRoom::set_floor(unsigned short int floor){
    this->floor = floor;
}
short unsigned int ClassRoom::get__id(){
    return this->__id;
}
short unsigned int ClassRoom::get_number_of_desks(){
    return this->number_of_desks;
}
bool ClassRoom::get_projector(){
    return this->projector;
}
unsigned short int ClassRoom::get_floor(){
    return this->floor;
}
void ClassRoom::print_classroom_info(){
    cout<<"El aula "<<get__id()<<" posee "<<get_number_of_desks()<<" pupitres, "<<(get_projector()?"tiene proyector":"no tiene proyector")<<" esta ubicada en el piso "<<floor<<" ";
}