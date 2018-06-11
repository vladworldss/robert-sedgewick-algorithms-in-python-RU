/*
 * Заголовочные файлы Программ 3.3 и 3.4
 */

#ifndef CHAPTER03_POINT_H
#define CHAPTER03_POINT_H

/*Размер атрибута координаты типа Point. */
#define POINT_COORD_SIZE 32

/*Размер строкового представления типа Point. */
#define POINT_STR_SIZE 128


typedef struct {
    float x;
    float y;
} Point;

/*Функция вычисляет расстояние между двумя точками.
 * Возвращает корень из суммы квадратов расстояний.
 * */
float distance(Point, Point);

/*Функция преобразовывает декартовы координаты в полярные.*/
void polar(float, float, float*, float*);

/*Конвертирует вещественное число в строку с точностью до 3-х знаков.
 * Результат записывается в переданный буффер.
 * Возвращает 0 если все успешно, -1 - в случае ошибки.
 * Проверяет указатель на NULL.
 * */
int int_to_str(float, char*);

/*Функция отображение типа Point в строковом виде:
 * <x=Point.x; y=Point.y>
 * */
int point_to_sting(Point, char*);

#endif //CHAPTER03_POINT_H
