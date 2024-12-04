Programación III: Proyecto Final (2024-2)
Este proyecto fue realizado por el equipo de desarrollo, donde cada integrante trabajó en diferentes repositorios. A continuación se listan los integrantes:
- Anthony Chavez Ayme
- Adrian Luis Pacheco Sulluchuco
- Marco Antonio Madrid Gonzales 
- Llorent Eloy Nunayalle Brañes 
Cada uno contribuyó en distintas áreas del proyecto, y las contribuciones fueron integradas en este repositorio final.

Movie Search Application
Este proyecto es una aplicación de búsqueda de películas que permite a los usuarios buscar películas por palabra clave o etiquetas. La aplicación utiliza un Trie para realizar búsquedas rápidas y eficientes y un sistema de indexación de etiquetas para facilitar la búsqueda por categorías. Además, ofrece la funcionalidad de guardar películas en la lista "Ver Más Tarde" para su visualización futura.

Características principales
Búsqueda por palabra clave: Los usuarios pueden buscar películas por palabra clave en el título o la sinopsis. Los resultados se ordenan por relevancia según la frecuencia con que la palabra clave aparece en las películas.
Búsqueda por etiqueta: Los usuarios pueden buscar películas utilizando etiquetas específicas, como "acción", "comedia", "drama", etc.
Lista "Ver Más Tarde": Los usuarios pueden guardar películas en una lista para verlas más tarde, permitiéndoles hacer un seguimiento de las películas que les gustaría ver.
Interfaz de usuario basada en consola: Un menú interactivo en la consola permite al usuario navegar por las opciones disponibles, realizar búsquedas y ver detalles de las películas.
Trie para búsqueda rápida: Se utiliza un Trie para almacenar y buscar rápidamente las palabras clave en los títulos y sinopsis de las películas, mejorando la eficiencia de las búsquedas.
Indexación por etiquetas: Las películas están indexadas por sus etiquetas, lo que permite realizar búsquedas rápidas por categoría.
Tecnologías y herramientas
C++: Lenguaje utilizado para el desarrollo de la aplicación.
Trie: Estructura de datos utilizada para optimizar la búsqueda de palabras clave en los títulos y sinopsis.
Indexación por etiquetas: Estructura de índice que permite organizar las películas por sus etiquetas asociadas, facilitando la búsqueda por categoría.
Archivos CSV: Los datos de las películas se cargan desde un archivo CSV que contiene información sobre cada película.
Archivos de texto: Se utiliza un archivo de texto para almacenar la lista de películas que los usuarios desean guardar para ver más tarde.
Flujo de Funciones
A continuación, se explica el propósito y la implementación de las funciones principales en la aplicación.

1. Trie y TrieNode
Función principal: Trie
El Trie es una estructura de datos que permite realizar búsquedas rápidas de palabras clave en los títulos y sinopsis de las películas.

insert(const string& word, Pelicula* pelicula):
Inserta una palabra en el Trie. Para cada palabra que se inserta, se almacena también una referencia a la película correspondiente. Esto permite realizar búsquedas rápidas de todas las películas que contienen esa palabra clave.
Además, en cada nodo de la palabra, se incrementa un contador que refleja cuántas veces se ha encontrado esa palabra en la película.

search(const string& word):
Realiza una búsqueda en el Trie para encontrar todas las películas asociadas a una palabra clave. El resultado es un mapa que devuelve las películas y la frecuencia con que esa palabra clave aparece en cada una de ellas.

Función principal: TrieNode
Un TrieNode es una estructura que almacena un carácter y los nodos hijos, así como una bandera que indica si el nodo corresponde al final de una palabra. Además, cada nodo tiene un mapa de películas asociadas y su frecuencia.

2. Menu
El menú principal proporciona una interfaz de usuario interactiva para permitir al usuario realizar diversas acciones, como buscar películas por palabra clave o por etiqueta.

iniciarMenu(vector<Pelicula*>& peliculas, Trie& trie, unordered_map<string, vector<Pelicula*>>& tagIndex, VerMasTarde& vmt):
Esta función es el punto de entrada al menú interactivo. Primero, carga los datos de las películas desde un archivo CSV utilizando la función cargarDatos(). Luego, presenta un menú con varias opciones:

Buscar películas por palabra clave.
Buscar películas por etiqueta.
Salir del programa.
cargarDatos(const string& filename, vector<Pelicula*>& peliculas, Trie& trie, unordered_map<string, vector<Pelicula*>>& tagIndex):
Carga los datos de las películas desde un archivo CSV. Esta función también indexa las películas por sus etiquetas y las inserta en el Trie para las búsquedas por palabra clave.

3. buscarPorPalabraClave(Trie& trie, VerMasTarde& vmt)
Esta función permite al usuario buscar películas usando palabras clave en el título o sinopsis.

El programa toma una palabra o frase clave del usuario y la divide en palabras individuales.
Luego, para cada palabra clave, realiza una búsqueda en el Trie para encontrar las películas que contienen esa palabra.
Los resultados se ordenan por relevancia según la frecuencia con que la palabra clave aparece en las películas.
Los resultados se muestran en páginas (5 resultados por página) para facilitar la navegación.
El usuario puede seleccionar una película para ver más detalles o agregarla a su lista "Ver Más Tarde".
4. buscarPorTag(const unordered_map<string, vector<Pelicula*>>& tagIndex, VerMasTarde& vmt)
Esta función permite al usuario buscar películas por una etiqueta específica (por ejemplo, "acción", "comedia", etc.).

El programa muestra una lista de todas las etiquetas disponibles y permite al usuario seleccionar una.
Después de seleccionar una etiqueta, el programa muestra todas las películas asociadas con esa etiqueta, divididas en páginas de 5 resultados cada una.
Al igual que en la búsqueda por palabra clave, el usuario puede elegir una película para ver más detalles o agregarla a la lista de "Ver Más Tarde".
5. mostrarPelicula(Pelicula* pelicula, VerMasTarde& vmt)
Esta función muestra la información detallada de una película seleccionada, incluyendo:

ID IMDB
Título
Sinopsis
Etiquetas
Fuente de la sinopsis
División (split)
Después de mostrar la información, el programa le permite al usuario guardar la película en la lista "Ver Más Tarde" si no la ha guardado previamente. Si la película ya está en la lista "Ver Más Tarde", solo se le ofrece la opción de volver al menú anterior.

6. VerMasTarde
La clase VerMasTarde permite almacenar y recuperar las películas que los usuarios desean guardar para ver más tarde.

insertarpelicula(string pelicula):
Añade una película a la lista "Ver Más Tarde". Las películas se almacenan en un archivo de texto (ver más tarde) para que los usuarios puedan consultarlas en futuras ejecuciones del programa.

obtenerpeliculasenvermastarde():
Lee las películas guardadas en la lista "Ver Más Tarde" desde el archivo y devuelve un vector con todas ellas.

mostrar_vermastarde():
Muestra las películas que están en la lista "Ver Más Tarde".

Estructura de Archivos
main.cpp: Contiene el punto de entrada principal del programa y maneja la interacción con el usuario.
Trie.cpp y TrieNode.cpp: Implementan la estructura de datos Trie para la búsqueda eficiente de palabras clave.
Pelicula.cpp: Define la clase Pelicula que contiene la información de cada película (título, sinopsis, etiquetas, etc.).
DataLoader.cpp: Se encarga de cargar los datos de las películas desde un archivo CSV y de indexar las películas en el Trie y por etiquetas.
Utils.cpp: Contiene funciones auxiliares para el procesamiento de cadenas de texto, la carga de stopwords y la división de palabras.
VerMasTarde.cpp: Implementa la funcionalidad para almacenar las películas que el usuario quiere ver más tarde.
Menu.cpp: Contiene la lógica para mostrar y gestionar el menú interactivo de la aplicación.

