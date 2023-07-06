import requests
import os
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np

"""
Utilizacion de pandas y matplotlib para la graficacion de datos
Licencia: MIT
"""


# Funcion que se encarga de descargar el archivo csv y guardarlo en la carpeta csv_data # noqa
def data_retrieval(link_csv):
    dir_path = os.path.join(os.getcwd(), "csv_data")

    # Sino existe la carpeta csv_data se crea
    try:
        if (not os.path.exists(dir_path)):
            os.makedirs(dir_path)
    except OSError:
        print("Error al crear la carpeta")
    path = os.path.join(dir_path, "trips_by_distance.csv")
    try:
        response = requests.get(link_csv)
    except:
        print("Error al obtener el archivo")

    # Se guarda el archivo csv en la carpeta csv_data
    try:
        with open(path, "wb") as f:
            f.write(response.content)
    except:
        print("Error al guardar el archivo")
    df_complete_data = pd.read_csv(path)
    # Se retorna el dataframe con los datos completos
    return df_complete_data


# Funcion que se encarga de limpiar los datos del dataframe
def clean_data(df_complete_data, name_serie, year=-1):
    # Se eliminan las filas que no tienen datos en las columnas de los viajes con un dropna # noqa 
    df_complete_data.dropna(subset=["trips_1", "trips_1_3", "trips_3_5",
                                    "trips_5_10", "trips_10_25", "trips_25_50",
                                    "trips_50_100", "trips_100_250",
                                    "trips_250_500",
                                    "trips_500"], inplace=True)
    # Al final de la tabla vienen los datos resumiendo los viajes por estado, se eliminan # noqa
    df_complete_data = df_complete_data[df_complete_data["state_code"].isna()==True] # noqa

    # Dependiendo del año se filtran los datos
    if year == "2019":
        df_complete_data = df_complete_data[df_complete_data["state_code"].isna() == True & df_complete_data["date"].str.contains("2019")]# noqa
    if year == "2020":
        df_complete_data = df_complete_data[df_complete_data["state_code"].isna() == True & df_complete_data["date"].str.contains("2020")]# noqa

    df_serie = df_complete_data[name_serie]

    # Se retorna la serie con los datos limpios
    return df_serie
