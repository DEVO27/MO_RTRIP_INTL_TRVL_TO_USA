<h1 align="center">MO_RTRIP_INTL_TRVL_TO_USA</h1>

This is a data retrieval application used for searching and organizing reported International flights departing from US Airports amid January and June 2020 from the 
<a href="https://data.transportation.gov/Aviation/International_Report_Passengers/xgub-n9bw).">US Department of Transportation</a>. The application's intended purpose is to search tables from a reduced dataset provided in the data.csv file and record the outcome of several flight path summaries.

 

<details>
  <summary>Video</summary>
  VIDEO WILL GO HERE
</details>
 
<details>
<summary>Installation</summary>
You can install the program by copying the relevant directories right into ~/.vim: 
 
 ```
 $ git clone https://github.com/DEVO27/MO_RTRIP_INTL_TRVL_TO_USA.git
```
 
Onced downloaded, add the following line to the terminal from within the files working directory
 
```
 ./main
```
If an error occurred then the executable was not created or added to the file folder. Run the command ``make`` and then the step above. This creates an executable file. 
 
```
-> make
clang -c main.c
clang -c route-records.c 
clang main.o route-records.o -o main -lm
rm -rf *.o
 ```
 
 </details>
 
 <details>
 <summary>Usage</summary>

# Types of Searches
 There are a variety of different techniques used to search for flight records within the provided dataset. 
 The following is a list of searchable routes that can be mapped and recorded:
 - Origin
 - Destination
 - Route
 - Airline
 <details>
  <summary>Origin</summary>
  Route records can be searched by the airport from which they originated. A flight for instance originated from SFO (San Francisco International Airport) would result in all
  flights departing from SFO within 6 months of their departure.
  
  <br>Choose option 2 to find flights based on origin. Its input must be a 3 letter IATA code from within the dataset. If the origin was SFO the following would be printed. 
  
  ```
  Searching by origin...
CX (SFO-HKG) PR (SFO-CEB) CI (SFO-TPE) AS (SFO-PVR) 
  AC (SFO-YYZ) LH (SFO-MUC) BA (SFO-LHR) NH (SFO-NRT) BR 
  (SFO-TPE) PR (SFO-MNL) AC (SFO-YVR) OZ (SFO-ICN) KE (SFO-ICN) 
  EK (SFO-DXB) UA (SFO-YVR) AN (SFO-YYC) UA (SFO-BOM) CZ (SFO-WUH) 
  MU (SFO-TAO) UA (SFO-CTU) UA (SFO-BCN) UA (SFO-PEK) UA (SFO-PVG) 
  UA (SFO-HKG) SQ (SFO-HKG) CX (SFO-NRT) FI (SFO-KEF) CX (SFO-KIX) 
  4O (SFO-GDL) 
99 matches were found.

Statistics
Total Passengers: 2560583
Total Passengers in Month 1: 1183469
Total Passengers in Month 2: 840282
Total Passengers in Month 6: 41541

Average Passengers per Month: 426764
  ```
  **The example above is greatly simplified**

  
  </details>
 
  <details>
  <summary>Route</summary>
   Specific routes from two international airports can be searched given their IATA airport code. 
  </details>
 
 <details>
  <summary>Destination</summary>
  The same as with origin, if the airport code is known the corresponding 
  flight records will be presented along with passenger statistics of each 
  month traveled. 
 </details>


 <details>
  <summary>Dataset</summary>


| Month   | Usage_Apt | Fg_Apt | Carrier | Type      | Total |
| ---     | ---       | ---    | ---     | ---       | ---   |
|6        |TEB        |RIX     |LF       |Passengers | 2     |
|6        |TEB        |FAB     |LF       |Passengers |2      |
|6        |SJU        |POS     |3M       |Passengers |297    |
|5        |SJU        |GEO     |X9       |Passengers |86     |
|5        |SJU        |DOM     |3M       |Passengers |63     |
|5        |SJU        |BGI     |3M       |Passengers |22     |
|5        |RSW        |YYZ     |DL       |Passengers |29     |
|4        |ORD        |WAW     |LO       |Passengers |554    |
|4        |OPF        |NCE     |LF       |Passengers |2      |
|4        |MIA        |SCL     |5Y       |Passengers |1      |
|4        |MIA        |POS     |WL       |Passengers |109    |
   </details>
</details>




