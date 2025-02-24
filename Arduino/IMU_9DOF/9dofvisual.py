import serial
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Set up serial connection
ser = serial.Serial('/dev/ttyACM0', 115200)  # Change to '/dev/ttyACM0' for your setup

# Create lists to store data
accel_x = []
accel_y = []
accel_z = []
gyro_x = []
gyro_y = []
gyro_z = []
mag_x = []
mag_y = []
mag_z = []

# Start reading data
plt.ion()  # Interactive mode for real-time plotting
fig = plt.figure(figsize=(12, 8))

# Create 3D subplots
ax1 = fig.add_subplot(131, projection='3d')
ax2 = fig.add_subplot(132, projection='3d')
ax3 = fig.add_subplot(133, projection='3d')

while True:
    line = ser.readline().decode('utf-8').strip()
    
    if line:
        try:
            # Debug print to understand the received line
            print(line)
            
            # Parse the sensor data from the serial output
            if 'Accel' in line:
                parts = line.split(' ')
                # Ensure the line contains the expected number of elements
                if len(parts) >= 4:
                    accel_x.append(float(parts[1].split(':')[1]))
                    accel_y.append(float(parts[2].split(':')[1]))
                    accel_z.append(float(parts[3].split(':')[1]))
            elif 'Gyro' in line:
                parts = line.split(' ')
                if len(parts) >= 4:
                    gyro_x.append(float(parts[1].split(':')[1]))
                    gyro_y.append(float(parts[2].split(':')[1]))
                    gyro_z.append(float(parts[3].split(':')[1]))
            elif 'Mag' in line:
                parts = line.split(' ')
                if len(parts) >= 4:
                    mag_x.append(float(parts[1].split(':')[1]))
                    mag_y.append(float(parts[2].split(':')[1]))
                    mag_z.append(float(parts[3].split(':')[1]))

        except Exception as e:
            print(f"Error parsing line: {line} -> {e}")



        # Plot the 3D accelerometer data
        ax1.scatter(accel_x, accel_y, accel_z, label="Accel Data", c='r', s=10)
        ax1.set_title("Accelerometer Data")
        ax1.set_xlabel("X")
        ax1.set_ylabel("Y")
        ax1.set_zlabel("Z")
        ax1.legend()

        # Plot the 3D gyroscope data
        ax2.scatter(gyro_x, gyro_y, gyro_z, label="Gyro Data", c='g', s=10)
        ax2.set_title("Gyroscope Data")
        ax2.set_xlabel("X")
        ax2.set_ylabel("Y")
        ax2.set_zlabel("Z")
        ax2.legend()

        # Plot the 3D magnetometer data
        ax3.scatter(mag_x, mag_y, mag_z, label="Mag Data", c='b', s=10)
        ax3.set_title("Magnetometer Data")
        ax3.set_xlabel("X")
        ax3.set_ylabel("Y")
        ax3.set_zlabel("Z")
        ax3.legend()

        # Redraw the plot
        plt.draw()
        plt.pause(0.05)
        # Clear plots
        ax1.cla()
        ax2.cla()
        ax3.cla()
