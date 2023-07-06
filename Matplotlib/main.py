from lib.plots import *
def main():
    # Se obtiene la informacion de la API y se limpia
    link_csv = "https://data.bts.gov/resource/w96p-f2qv.csv"
    df_complete_data = data_retrieval(link_csv)
    serie_data = clean_data(df_complete_data, "trips_1")
    plot_normal_distribution(serie_data)
    serie_data_2019 = clean_data(df_complete_data, "trips_1", "2019")
    serie_data_2020 = clean_data(df_complete_data, "trips_1", "2020")
    # Se grafican los histogramas
    subplot_normal_distribution(serie_data_2019, serie_data_2020)

    # Impresion de info general
    print("Emmanuel Chavarria Solis")
    print("B51977")
    print("Tarea 5\n")

    # Se imprime la informacion estadistica de la serie de datos para el 2019 y 2020 # noqa
    print("Descripcion de la informacion en el 2019")
    print(serie_data_2019.describe())
    print("Descripcion de la informacion en el 2020")
    print(serie_data_2020.describe())

    # Pie chart se genera
    pie_population_at_home_2019 = clean_data(df_complete_data,
                                             "pop_stay_at_home", "2019")
    pie_population_not_at_home_2019 = clean_data(df_complete_data, "pop_not_stay_at_home", "2019") # noqa
    pie_population_at_home_2020 = clean_data(df_complete_data, "pop_stay_at_home", "2020") # noqa
    pie_population_not_at_home_2020 = clean_data(df_complete_data, "pop_not_stay_at_home", "2020") # noqa
    pie_chart(pie_population_at_home_2019.mean(), pie_population_not_at_home_2019.mean(), pie_population_at_home_2020.mean(), pie_population_not_at_home_2020.mean()) # noqa

    # Scatterplot se genera
    scatter_make(serie_data_2019, serie_data_2020)


if __name__ == "__main__":
    main()
