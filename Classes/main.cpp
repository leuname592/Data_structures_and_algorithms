/**
 * @file main.cpp
 * 
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * 
 * @brief Main en donde se llaman todos los metodos de interes.
 * 
 * @date 2023-04-19
 * 
 * @copyright MIT
 * 
 */

#include "libraries.hpp"
#include "classes_structure.hpp"
#include "functions_structure.hpp"

int main()
{
    uint8_t classrooms_per_floor;
    uint8_t property_number;
    uint8_t classroom_building_number;
    uint8_t number_of_desks;
    uint8_t projector;
    //Init Campus
    Campus Facio;
    Facio = add_campus("Sede Rodrigo Facio");

    //Initializing variables for Finca Aire
    property_number=0;
    //Adding Finca Aire information
    /**
     * @brief Se agrega una Finca
     * 
     */
    Facio = add_property(Facio, true, "Finca Aire");
    /**
     * @brief Se agregan edificios de parqueos
     * 
     */
    Facio = add_parking_building(property_number, Facio,"Edificio de parqueos nitrogeno",true,5,2000,4);
    Facio = add_parking_building(property_number, Facio,"Edificio de parqueos oxigeno",false,5,2000,4);
    /**
     * @brief Se agregan edificios de aulas
     * 
     */
    Facio = add_classroom_building(property_number,Facio,"Edificio de periodismo",true,7,true,true);
    classrooms_per_floor = 10;
    classroom_building_number=0;
    number_of_desks=35;
    projector=false;
    /**
     * @brief Se agregan multiples aulas por cada edificio
     * 
     */
    Facio = add_multiple_classrooms(Facio,&add_classroom,classrooms_per_floor,property_number,classroom_building_number,number_of_desks,projector);

    Facio = add_classroom_building(property_number,Facio,"Edificio de sociales",true,10,true,true);
    classrooms_per_floor = 15;
    classroom_building_number=1;
    number_of_desks=25;
    projector=true;
    Facio = add_multiple_classrooms(Facio,&add_classroom,classrooms_per_floor,property_number,classroom_building_number,number_of_desks,projector);

    
    Facio = add_classroom_building(property_number,Facio,"Edificio de filosofia",true,5,true,true);
    classrooms_per_floor = 84;
    classroom_building_number=2;
    number_of_desks=25;
    projector=true;
    Facio = add_multiple_classrooms(Facio,&add_classroom,classrooms_per_floor,property_number,classroom_building_number,number_of_desks,projector);

    //Initializing variables for Finca Aire
    property_number=1;
    //Adding Finca Tierra information
    Facio = add_property(Facio, true, "Finca Tierra");
    Facio = add_parking_building(property_number, Facio,"Edificio de parqueos carbono",true,5,31416,4);
    
    Facio = add_classroom_building(property_number,Facio,"Edificio de geologia",true,5,true,true);
    classrooms_per_floor = 10;
    classroom_building_number=0;
    number_of_desks=20;
    projector=true;
    Facio = add_multiple_classrooms(Facio,&add_classroom,classrooms_per_floor,property_number,classroom_building_number,number_of_desks,projector);

    
    Facio = add_classroom_building(property_number,Facio,"Edificio de veterinaria",true,4,false,true);
    classrooms_per_floor = 7;
    classroom_building_number=1;
    number_of_desks=22;
    projector=true;
    Facio = add_multiple_classrooms(Facio,&add_classroom,classrooms_per_floor,property_number,classroom_building_number,number_of_desks,projector);


    //Initializing variables for Finca Aire
    property_number=2;    
    //Adding Finca Fuego information
    Facio = add_property(Facio, true, "Finca Fuego");
    Facio = add_parking_building(property_number, Facio,"Edificio de parqueos golden state",true,5,27183,13);
    Facio = add_classroom_building(property_number,Facio,"Edificio de artes pirotecnicas",true,4,false,true);
    classrooms_per_floor = 4;
    classroom_building_number=0;
    number_of_desks=7;
    projector=false;
    Facio = add_multiple_classrooms(Facio,&add_classroom,classrooms_per_floor,property_number,classroom_building_number,number_of_desks,projector);


    //Initializing variables for Finca Aire
    property_number=3;
    //Adding Finca Pobre information
    Facio = add_property(Facio, false, "Finca Pobre");

    //Printing Campus information
    /**
     * @brief Se imprime la informacion del campus
     * 
     */
    print_campus(Facio);
    return 0;
}
