/**
 * @file functions_structure.hpp
 * 
 * @author Emmanuel Chavarria Solis (leuname592@hotmail.com)
 * 
 * @brief Este file declara los prototipos de las funciones
 * 
 * @date 2023-04-19
 * 
 * @copyright MIT
 * 
 */

#pragma once
#include "libraries.hpp"

/**
 * @brief Agrega un campus
 * 
 * @param campus_name Nombre del campus
 * @return Campus 
 */
Campus add_campus(string campus_name);

/**
 * @brief Agrega una finca
 * 
 * @param campus Objeto Campus
 * @param bus Indica si hay presencia de un bus
 * @param property_name Nombre de la finca
 * @return Campus 
 */
Campus add_property(Campus campus, bool bus, string property_name);

/**
 * @brief Fincas en donde el bus pasa
 * 
 * @param properties Vector de fincas 
 * @return string 
 */
string bus_enabled_in_properties(vector<Property> properties);

/**
 * @brief Agrega un edificio de parqueos
 * 
 * @param property_number Numero de finca
 * @param Campus Objeto Campus
 * @param parking_building_name Nombre del edificio de parqueos 
 * @param elevator Presencia de elevador
 * @param number_of_floors Numero de pisos
 * @param number_of_parking_spots Numero de estacionamientos
 * @param number_of_washrooms Numero de baños
 * @return Campus 
 */
Campus add_parking_building(uint8_t property_number, Campus Campus, string parking_building_name, bool elevator, short unsigned int number_of_floors, short unsigned int number_of_parking_spots,short unsigned int number_of_washrooms);

/**
 * @brief 
 * 
 * @param property_number Numero de finca
 * @param Campus Objeto Campus
 * @param classroom_building_name Nombre del edificio de aulas
 * @param elevator Presencia de elevador
 * @param number_of_floors Numero de pisos
 * @param cafeteria Presencia de una soda en el edificio
 * @param auditorium Presencia de un auditorio en el edificio
 * @return Campus 
 */
Campus add_classroom_building(uint8_t property_number,Campus Campus, string classroom_building_name, bool elevator, short unsigned int number_of_floors, bool cafeteria, bool auditorium);

/**
 * @brief Agrega una aula al edificio de aulas
 * 
 * @param property_number Numero de finca
 * @param classroom_building_number Numero del edificio
 * @param Campus Objeto Campus
 * @param number_of_desks Numero de pupitres
 * @param floor Piso en el que se encuentra el aula
 * @param projector Presencia de proyector
 * @return Campus 
 */
Campus add_classroom(uint8_t property_number, uint8_t classroom_building_number, Campus Campus, short unsigned int number_of_desks, short unsigned int floor, bool projector);

/**
 * @brief 
 * 
 * @param Campus Objeto Campus
 * @param add_clasroom Funcion gregar una aula
 * @param classrooms_per_floor Numero de aulas por piso
 * @param property_number Numero de la finca
 * @param classroom_building_number Numero del edificio de aulas
 * @param number_of_desks Numero de pupitres
 * @param projector Presencia de proyectores
 * @return Campus 
 */
Campus add_multiple_classrooms(Campus Campus, decltype(Campus)(*add_clasroom)(uint8_t,uint8_t,decltype(Campus),short unsigned int,short unsigned int,bool),uint8_t classrooms_per_floor,uint8_t property_number,uint8_t classroom_building_number,uint8_t number_of_desks, bool projector);

/**
 * @brief Imprime toda la informacion del campus
 * 
 * @param campus_to_print Objeto del campus a imprimir
 */
void print_campus(Campus campus_to_print);