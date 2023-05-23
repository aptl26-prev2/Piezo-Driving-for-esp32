import numpy as np
import librosa   
import json

driverSamplingRate = 8000

data, s = librosa.load('file.wav', sr=driverSamplingRate)

print("type of data: ", type(data))
print("len of data", len(data))
print("data: ", data[:10])

# print(data_list[:10])

with open("wave.json", "w") as f:
    json.dump(data[:10].tolist(), f)
