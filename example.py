from serialToExcel import SerialToExcel
import time

serialToExcel = SerialToExcel("COM3", 9600)

# Definir las columnas y número de registros
columnas = ["Nro Lectura", "Valor"]
serialToExcel.setColumns(columnas)

serialToExcel.setRecordsNumber(50)


# Leer desde el puerto serial
serialToExcel.readPort()

# Escribir en el archivo Excel
serialToExcel.writeFile("temperaturafinal.xls")