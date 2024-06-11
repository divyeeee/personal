import requests
import sys
def main():
    if(len(sys.argv)!=2 or sys.argv[1].count(".")>1):
        sys.exit("Missing command line arguement")
    if(sys.argv[1].count(".")==1):
        fir,sep,las=sys.argv[1].partition(".")
        if(fir.isnumeric()==False or las.isnumeric()==False):
            sys.exit("Command line arguement is not a number")
        sys.argv[1]=fir+sep+las
    else:
        if(sys.argv[1].isnumeric()==False):
            sys.exit("Command line arguement is not a number")

    response=requests.get("https://api.coindesk.com/v1/bpi/currentprice.json")
    dict=response.json()
    listt=dict["bpi"]
    listt2=listt["USD"]
    amount=float(sys.argv[1])*listt2["rate_float"]
    print(f"${amount:,.4f}")
main()

