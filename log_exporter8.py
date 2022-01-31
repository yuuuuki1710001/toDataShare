# import kafka
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
    ### Read Heart Rate data from csv file
    with open(input_file) as f:
        load_csv =  csv.DictReader(f)
        for line in load_csv:
            ret.append(line)
    return ret
        


def nodeLogger(log_data, influx_client):

    ### format of log_data 
    data_id = "test"
    data_type = "float"

    #data_value = random.randint(1, 100)
    timestamp1 = log_data['timestamp_now1']
    timestamp2 = log_data['timestamp_now2']
    timestamp3 = log_data['timestamp_now3']
    timestamp4 = log_data['timestamp_now4']
    timestamp5 = log_data['timestamp_now5']
    timestamp6 = log_data['timestamp_now6']
    timestamp7 = log_data['timestamp_now7']
    timestamp8 = log_data['timestamp_now8']
    #data_value = log_data['delta']
    data_value1 = log_data['callback1']
    data_value2 = log_data['callback2']
    data_value3 = log_data['callback3']
    data_value4 = log_data['callback4']
    data_value5 = log_data['callback5']
    data_value6 = log_data['callback6']
    data_value7 = log_data['callback7']
    data_value8 = log_data['callback8']
    data_value9 = log_data['timestamp_start1']
    data_value10 = log_data['timestamp_start2']
    data_value11 = log_data['timestamp_start3']
    data_value12 = log_data['timestamp_start4']
    data_value13 = log_data['timestamp_start5']
    data_value14 = log_data['timestamp_start6']
    data_value15 = log_data['timestamp_start7']
    data_value16 = log_data['timestamp_start8']

    #try:
        #data_value = int(data_value)
    timestamp1 = isfloat(timestamp1)
    timestamp2 = isfloat(timestamp2)
    timestamp3 = isfloat(timestamp3)
    timestamp4 = isfloat(timestamp4)
    timestamp5 = isfloat(timestamp5)
    timestamp6 = isfloat(timestamp6)
    timestamp7 = isfloat(timestamp7)
    timestamp8 = isfloat(timestamp8)
        
        
    data_value1 = isfloat(data_value1)
    data_value2 = isfloat(data_value2)
    data_value3 = isfloat(data_value3)
    data_value4 = isfloat(data_value4)
    data_value5 = isfloat(data_value5)
    data_value6 = isfloat(data_value6)
    data_value7 = isfloat(data_value7)
    data_value8 = isfloat(data_value8)
    data_value9 = isfloat(isfloat(timestamp1) - isfloat(data_value9))
    data_value10 = isfloat(isfloat(timestamp2) - isfloat(data_value10))
    data_value11 = isfloat(isfloat(timestamp3) - isfloat(data_value11))
    data_value12 = isfloat(isfloat(timestamp4) - isfloat(data_value12))
    data_value13 = isfloat(isfloat(timestamp5) - isfloat(data_value13))
    data_value14 = isfloat(isfloat(timestamp6) - isfloat(data_value14))
    data_value15 = isfloat(isfloat(timestamp7) - isfloat(data_value15))
    data_value16 = isfloat(isfloat(timestamp8) - isfloat(data_value16))
    #except Exception as e:
    #    print(f'doly GG {e}')
        # return

    ###Timezone should be UTC
    #UTC = datetime.timezone.utc
    #timestamp = datetime.datetime.now(UTC)
    #timestamp = log_data[]


    JST = datetime.timezone(datetime.timedelta(hours=+9), 'JST')
    UTC = datetime.timezone(datetime.timedelta(hours=+0), 'UTC')
    ts1 = datetime.datetime.fromtimestamp(timestamp1, tz=JST)
    ts2 = datetime.datetime.fromtimestamp(timestamp2, tz=JST)
    ts3 = datetime.datetime.fromtimestamp(timestamp3, tz=JST)
    ts4 = datetime.datetime.fromtimestamp(timestamp4, tz=JST)
    ts5 = datetime.datetime.fromtimestamp(timestamp5, tz=JST)
    ts6 = datetime.datetime.fromtimestamp(timestamp6, tz=JST)
    ts7 = datetime.datetime.fromtimestamp(timestamp7, tz=JST)
    ts8 = datetime.datetime.fromtimestamp(timestamp8, tz=JST)
    tn1 = datetime.datetime.fromtimestamp(data_value9, tz=JST)
    tn2 = datetime.datetime.fromtimestamp(data_value10, tz=JST)
    tn3 = datetime.datetime.fromtimestamp(data_value11, tz=JST)
    tn4 = datetime.datetime.fromtimestamp(data_value12, tz=JST)
    tn5 = datetime.datetime.fromtimestamp(data_value13, tz=JST)
    tn6 = datetime.datetime.fromtimestamp(data_value14, tz=JST)
    tn7 = datetime.datetime.fromtimestamp(data_value15, tz=JST)
    tn8 = datetime.datetime.fromtimestamp(data_value16, tz=JST)

    timestamp1 = ts1.astimezone(UTC).replace(tzinfo=None).isoformat()
    #data_value9 = isfloat(str(tn1 - ts1))
    #data_value10 = isfloat(str(tn2 - ts2))
    #data_value11 = isfloat(str(tn3 - ts3))
    #data_value12 = isfloat(str(tn4 - ts4))
    #data_value13 = isfloat(str(tn5 - ts5))
    #data_value14 = isfloat(str(tn6 - ts6))
    #data_value15 = isfloat(str(tn7 - ts7))
    #data_value16 = isfloat(str(tn8 - ts8))
    # timestamp1 = datetime.date.fromtimestamp(timestamp1)

    #nodes_log_path = log_path + 'nodes_' + log_name + log_ext

    mem_name = "doly_monitoring8"
    ####mem_name = "doly_monitoring"

    data_to_db = [
                    {"measurement": mem_name,
                     "tags": {
                         "id": data_id,
                         "type": "byte-rate",
                        },
                     "time": timestamp1,
                     "fields": {
                         #"delta": data_value,
                         "callback1": data_value1,
                         "callback2": data_value2,
                         "callback3": data_value3,
                         "callback4": data_value4,
                         "callback5": data_value5,
                         "callback6": data_value6,
                         "callback7": data_value7,
                         "callback8": data_value8,
                         "timestamp_start1": data_value9,
                         "timestamp_start2": data_value10,
                         "timestamp_start3": data_value11,
                         "timestamp_start4": data_value12,
                         "timestamp_start5": data_value13,
                         "timestamp_start6": data_value14,
                         "timestamp_start7": data_value15,
                         "timestamp_start8": data_value16
                         }
                     }
                  ]
    print(f'{data_to_db}')  
    influx_client.write_points(data_to_db)
    #print('fuckyounow')

    #csvWriter(nodes_log_path, result)

    #print ("{} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {} {}".format(data_id, timestamp1, data_value1, data_value2, data_value3, data_value4, data_value5, data_value6, data_value7, data_value8, data_value9, data_value10, data_value11, data_value12, data_value13, data_value14, data_value15, data_value16))

def log_exporter(log_name, influx_client):

    data = readCSV(args[1])
    # data = ""

    json_list = []
    
    #for line in data:
        #json_list.append(line)
        #print(f'data is {jsonlist}')
        #print(f'line.attention = {line["attention"]}')
        #for i in range(len(data)):
    for line in data:
        #print(f'data is {line}')
        #print(f'line.attention = {line["attention"]}')
        #print(f'line.tn1 = {line["timestamp_now1"]}')
        #print(f'line.tn2 = {line["timestamp_now2"]}')
        #print(f'line.tn3 = {line["timestamp_now3"]}')
        #print(f'line.tn4 = {line["timestamp_now4"]}')
        #print(f'line.tn5 = {line["timestamp_now5"]}')
        #print(f'line.tn6 = {line["timestamp_now6"]}')
        #print(f'line.tn7 = {line["timestamp_now7"]}')
        #print(f'line.tn8 = {line["timestamp_now8"]}')
        #print(f'line.cal1 = {line["callback1"]}')
        #print(f'line.cal2 = {line["callback2"]}')
        #print(f'line.cal3 = {line["callback3"]}')
        #print(f'line.cal4 = {line["callback4"]}')
        #print(f'line.cal5 = {line["callback5"]}')
        #print(f'line.cal6 = {line["callback6"]}')
        #print(f'line.cal7 = {line["callback7"]}')
        #print(f'line.cal8 = {line["callback8"]}')
        #print(f'line.ts1 = {line["timestamp_start1"]}')
        #print(f'line.ts2 = {line["timestamp_start2"]}')
        #print(f'line.ts3 = {line["timestamp_start3"]}')
        #print(f'line.ts4 = {line["timestamp_start4"]}')
        #print(f'line.ts5 = {line["timestamp_start5"]}')
        #print(f'line.ts6 = {line["timestamp_start6"]}')
        #print(f'line.ts7 = {line["timestamp_start7"]}')
        #print(f'line.ts8 = {line["timestamp_start8"]}')
        #for i in range(len(data)):
        # convert to LIST to Dict
        ###
        nodeLogger(line, influx_client)
        #if i == len(data) -1:
        #    i=0
        time.sleep(1)


if __name__ == '__main__':

    main()
