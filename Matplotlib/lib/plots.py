from lib.data_retrieval import *

# Funcion que se encarga de graficar el histograma de la distribucion de los viajes # noqa
def plot_normal_distribution(df_serie):
    # Creacion del histograma, seteo de titulo y etiquetas
    plt.hist(df_serie/1000000, bins=100)
    plt.title("Histograma de la distribución de los viajes por distancia menores a una milla") # noqa
    plt.xlabel("Numero de viajes promedio por dia (millones)")
    plt.ylabel("Frecuencia del rango de viajes")
    plt.show()


# Funcion que se encarga de graficar el histograma de la distribucion de los viajes del 2019 y 2020 # noqa
def subplot_normal_distribution(df_serie1, df_serie2):
    # Creacion de la figura y los subplots
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))

    # Creacion de los histogramas, seteo de titulo y etiquetas
    ax1.hist(df_serie1/1000000, bins=50)
    ax1.set_title("Histograma (2019)")
    ax1.set_xlabel("Numero de viajes promedio por dia (millones)")
    ax1.set_ylabel("Frecuencia del rango de viajes")

    ax2.hist(df_serie2/1000000, bins=50)
    ax2.set_title("Histograma (2020)")
    ax2.set_xlabel("Numero de viajes promedio por dia (millones)")
    ax2.set_ylabel("Frecuencia del rango de viajes")
    plt.show()


# Pie chart de personas que decidieron quedarse en casa y las que no
def pie_chart(mean_not_2019, mean_2019, mean_not_2020, mean_2020):
    labels = 'Stay at home', 'Not stay at home'
    sizes_2019 = [mean_not_2019, mean_2019]
    sizes_2020 = [mean_not_2020, mean_2020]

    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(10, 5))
    # El explode se encarga de separar el pie chart
    explode = (0.1, 0)
    # Añadir porcentajes a los pie charts
    ax1.pie(sizes_2019, explode=explode, labels=labels, autopct='%1.1f%%', shadow=True, startangle=90) # noqa
    ax1.set_title("Pie chart (2019)")

    ax2.pie(sizes_2020, explode=explode, labels=labels, autopct='%1.1f%%', shadow=True, startangle=90) # noqa
    ax2.set_title("Pie chart (2020)")
    # Mostrar Figuras
    plt.show()


def scatter_hist(np_2019, np_2020, ax, ax_hist2019, ax_hist2020):
    # Inicializar los histogramas de 2019 y 2020
    ax_hist2019.tick_params(axis="x", labelbottom=False)
    ax_hist2020.tick_params(axis="y", labelleft=False)

    # Creacion del scatter plot
    ax.scatter(np_2019, np_2020)

    # Determinar el tamaño de los bins así como los limites de la figura
    binwidth = 5
    max_19_20 = max(np.max(np.abs(np_2019)), np.max(np.abs(np_2020)))
    lim = (int(max_19_20/binwidth) + 1) * binwidth

    bins = np.arange(100, lim + binwidth, binwidth)
    ax_hist2019.hist(np_2019, bins=bins)
    ax_hist2020.hist(np_2020, bins=bins, orientation='horizontal')


def scatter_make(serie_data_2019, serie_data_2020):
    fig = plt.figure(figsize=(6, 6))
    # Se define el gridsepec y el ratio de la figura, estos valores llevan un proceso de prueba y error # noqa
    gs = fig.add_gridspec(2, 2,  width_ratios=(4, 1), height_ratios=(1, 4),
                          left=0.1, right=0.9, bottom=0.1, top=0.9,
                          wspace=0.05, hspace=0.05)
    # Definir los ejes de la figura
    ax = fig.add_subplot(gs[1, 0])
    ax.set_xlabel("Scatter plot (2019) vs (2020)(Millones de viajes)")
    ax_hist2019 = fig.add_subplot(gs[0, 0], sharex=ax)
    ax_hist2020 = fig.add_subplot(gs[1, 1], sharey=ax)
    ax_hist2019.set_title("Histogram (2019)")
    ax_hist2020.set_title("(2020)", ha='left', va='center', position=(0.2, 0.5)) # noqa
    # Dibujar el scatter plot,se divide entre 1M y se ajustan las listas por limpieza de datos # noqa
    scatter_hist(serie_data_2019.to_numpy()/1000000, serie_data_2020.to_numpy()[1:]/1000000, ax, ax_hist2019, ax_hist2020) # noqa
    plt.show()
