def ladder_height(length,angle):
    import math
    radian=math.radians(angle)
    height=length*math.sin(radian)
    print(f"The height of the ladder is: ,{height} foot")
def main():
    measurements={16.0:75.0, 20.0:0.0, 24.0:45.0, 24.0:80.0}
    for i in measurements:
        ladder_height(i,measurements[i])
main()        