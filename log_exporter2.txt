import json
import csv
import os
import sys
import time
import datetime
import threading
import random
import subprocess

from influxdb import InfluxDBClient


args = sys.argv
setting_path = './setting.json'

with open(setting_path) as f:
    setting = json.load(f)


influxdb_ip = setting['influxdb ip']
influxdb_port = int(setting['influxdb port'])
influxdb_user = setting['influxdb user']
influxdb_pass = setting['influxdb pass']
influxdb_database = setting['influxdb database']

log_path = './logs/'
log_ext = '.csv'

kafka_key = "producer-topic-metrics"

def isfloat(temp):
    try:
        float(temp)
    except ValueError:
        return 0
    else:
        return float(temp)


def main():

    ### Connect InfluxDB
    influx_client = InfluxDBClient(influxdb_ip, influxdb_port, influxdb_user, influxdb_pass, influxdb_database)
    influx_client.create_database(influxdb_database)
    ###

    ### check output directory for log
    if os.path.exists(log_path) == False:
        os.makedirs(log_path)

    timestamp = datetime.datetime.now()
    log_name = timestamp.strftime('%Y-%m-%dT%H:%M:%SZ')

    print ('start kafka log exporter') 

    log_exporter(log_name, influx_client)


def csvWriter(file_path, data):

     with open(file_path, 'a') as f:
        writer = csv.writer(f)
        writer.writerow(data)

def readCSV(input_file):
    ret = []
    ### Read data from csv file
    with open(input_file) as f:
        load_csv =  csv.DictReader(f)
        for line in load_csv:
            ret.append(line)
    return ret
        


def nodeLogger(log_data, influx_client):

    ### format of log_data 
    data_id = "test"
    data_type = "float"

    timestamp1 = log_data['timestamp_now1']
    timestamp2 = log_data['timestamp_now2']
    data_value1 = log_data['callback1']
    data_value2 = log_data['callback2']
    data_value3 = log_data['timestamp_start1']
    data_value4 = log_data['timestamp_start2']

    timestamp1 = isfloat(timestamp1)
    timestamp2 = isfloat(timestamp2)
                
    data_value1 = isfloat(data_value1)
    data_value2 = isfloat(data_value2)
    data_value3 = isfloat(isfloat(timestamp1) - isfloat(data_value3))
    data_value4 = isfloat(isfloat(timestamp2) - isfloat(data_value4))


    JST = datetime.timezone(datetime.timedelta(hours=+9), 'JST')
    UTC = datetime.timezone(datetime.timedelta(hours=+0), 'UTC')
    ts1 = datetime.datetime.fromtimestamp(timestamp1, tz=JST)
    ts2 = datetime.datetime.fromtimestamp(timestamp2, tz=JST)
    tn1 = datetime.datetime.fromtimestamp(data_value3, tz=JST)
    tn2 = datetime.datetime.fromtimestamp(data_value4, tz=JST)

    timestamp1 = ts1.astimezone(UTC).replace(tzinfo=None).isoformat()

    mem_name = "doly_monitoring2"

    data_to_db = [
                    {"measurement": mem_name,
                     "tags": {
                         "id": data_id,
                         "type": "byte-rate",
                        },
                     "time": timestamp1,
                     "fields": {
                         "callback1": data_value1,
                         "callback2": data_value2,
                         "timestamp_start1": data_value3,
                         "timestamp_start2": data_value4
                         }
                     }
                  ]
    print(f'{data_to_db}')  
    influx_client.write_points(data_to_db)


def log_exporter(log_name, influx_client):

    data = readCSV(args[1])

    json_list = []
    
    for line in data:
        nodeLogger(line, influx_client)
        time.sleep(1)


if __name__ == '__main__':

    main()
