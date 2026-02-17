# Sistema IoT de Monitoreo Ambiental con ESP32, NiFi, InfluxDB y Grafana

##  Descripción del proyecto
Este proyecto implementa un sistema de monitoreo ambiental en tiempo real utilizando un microcontrolador **ESP32** y un sensor **DHT11**, integrados con una arquitectura moderna de procesamiento y visualización de datos basada en **Apache NiFi**, **InfluxDB** y **Grafana**.

El sistema permite capturar datos de **temperatura** y **humedad**, enviarlos mediante HTTP en formato JSON, procesarlos y almacenarlos como series de tiempo, y finalmente visualizarlos en dashboards interactivos.

Este proyecto simula un escenario real de Internet de las Cosas (IoT) aplicado al monitoreo ambiental.

---

## Arquitectura del sistema

ESP32 + Sensor DHT11  
⬇ HTTP (JSON)  
Apache NiFi (ingesta y transformación)  
⬇  
InfluxDB (base de datos de series de tiempo)  
⬇  
Grafana (visualización en tiempo real)

---

## Tecnologías utilizadas

- **ESP32**
- **Sensor DHT11**
- **Arduino IDE**
- **Apache NiFi**
- **InfluxDB**
- **Grafana**
- **HTTP / JSON**
- **InfluxDB Line Protocol**

---

## Flujo de datos

1. El ESP32 lee los valores de temperatura y humedad desde el sensor DHT11.
2. Los datos se envían a Apache NiFi mediante una solicitud HTTP POST en formato JSON.
3. Apache NiFi recibe, procesa y transforma los datos usando:
   - HandleHttpRequest
   - EvaluateJsonPath
   - ReplaceText
   - InvokeHTTP
4. Los datos transformados se almacenan en InfluxDB como series de tiempo.
5. Grafana consulta InfluxDB y muestra los datos en dashboards en tiempo real.

---

## Estructura de la base de datos (InfluxDB)

- **Base de datos / Bucket:** `iotdata`
- **Measurement:** `sensor_data`
- **Fields:**
  - `temperatura`
  - `humedad`
- **Tags:**
  - `ubicacion=huerta`
- **Timestamp:** generado automáticamente por InfluxDB

---

## Visualización en Grafana

El dashboard muestra:
- Gráfica de temperatura (°C)
- Gráfica de humedad relativa (%)

Los datos se actualizan automáticamente conforme el ESP32 envía nuevas lecturas al sistema.

---

## Ejecución del proyecto

1. Configurar red WiFi en el código del ESP32.
2. Cargar el código en el ESP32 usando Arduino IDE.
3. Importar el flujo de Apache NiFi.
4. Configurar InfluxDB (bucket y token).
5. Conectar Grafana a InfluxDB como fuente de datos.
6. Importar el dashboard en Grafana.

---

## Estructura del repositorio
## 📁 Estructura del repositorio

```text
iot-monitoring-esp32-nifi-influxdb/
│
├── README.md
│
├── esp32/
│   └── esp32_dht11_nifi.ino
│
├── nifi/
│   └── flow_nifi.json
│
├── influxdb/
│   └── consultas_influxdb.md
│
├── grafana/
│   └── dashboard.json
│
├── docs/
│   └── IoT_Monitoring_Report.pdf
│
└── images/
```
## Resultados (Screenshots)

### Grafana Dashboard
<img width="564" height="273" alt="Grafana Dashboard1" src="https://github.com/user-attachments/assets/67f53ed2-3c71-452e-8727-1d0387167f71" />
<img width="1034" height="464" alt="Grafana Dashboard2" src="https://github.com/user-attachments/assets/1fe1e536-c40d-4f1f-8062-2c14203b71ef" />



### Flujo en Apache NiFi
<img width="736" height="379" alt="flujo en Apache NiFi" src="https://github.com/user-attachments/assets/a768ffff-35f2-4e8b-a3d8-9a7d2be51655" />




### Datos almacenados en InfluxDB
<img width="419" height="560" alt="InfluxDB" src="https://github.com/user-attachments/assets/dba188a9-5e4a-42cc-9c77-33e48d8a3218" />



---

## Posibles mejoras

- Sustituir el sensor DHT11 por DHT22 para mayor precisión.
- Implementar alertas en Grafana.
- Integrar más sensores (CO₂, humedad del suelo, luminosidad).
- Migrar de HTTP a MQTT.
- Agregar autenticación y cifrado en la comunicación.
- Añadir etiquetas adicionales en InfluxDB (dispositivo, zona, etc.).

---

## Autor
**Iván Camilo Martínez Pinto**  
Ingeniero electronico
