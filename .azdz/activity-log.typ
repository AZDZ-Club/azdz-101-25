#set page(
  paper: "a4",
  margin: 1in,
  header: grid(
  columns:(auto, 1fr, auto, 1fr, auto),
  align: right+horizon,
  [#box(width: 72pt, image("./.azdz/img.png"))],
  [],
  [#text(font: "JetBrains Mono", size:10pt, weight:100)[#upper("Activity Log")]],
  [],
  [#text(font: "JetBrains Mono", size:10pt, weight:100)[#upper("Intended for: ") 2025-03-31]]),
  footer: grid(
  columns:(auto, 1fr, auto, 1fr, auto),
  align: right+horizon,
  [#text(font: "JetBrains Mono", size:10pt, weight:100)[#context counter(page).display()]],
  [],
  [#text(font: "JetBrains Mono", size:10pt, weight:100)[#upper("approved")]],
  [],
  [#text(font: "JetBrains Mono", size:10pt, weight:100)[#upper("Compiled On: ") #datetime.today().display()]])
)

#set text( font: "IBM Plex Sans", size: 12pt, weight:300)

#v(20pt)

= C/W 14 · Workshop · Orientation for New International Students

#v(20pt)

#list(indent: 72pt,
[Time: 13:15 - 14:15],
[Venue: E006],
[Responsible Person: Birnadin Erick ],
[Conductor: Aditi Pandey],
[Topic: Orientation & 4-Junction Traffic Light Controller]
)

#v(20pt)

== Abstract.

The goal of this workshop is to inform new internation students about AZDZ & what it 
has to offer. Continued by a demonstration of pre-stated Workshop Topic & hopefully 
able to finish it. At last, a competition of circuits realized by the students which clears a 
given traffic instance fast.

#v(20pt)


== Reference Schematic.

#figure(
  image("./.azdz/4-junc-int.jpeg", width:75%),
  caption: [
    4-Junction Intersection Traffic Light System
  ]
)

#v(15pt)

#figure(
  image("./.azdz/pedestrian-lane.jpeg", width:75%),
  caption: [
    Pedestrian-Automobile Lane Traffic Light System [Hands On]
  ]
)
#v(20pt)

== BoM.

#table(
  columns: 3,
  table.header[Item Name][Quantity][is in Stock?],
  [ESP 32s],[7],[Yes],
  [LEDs],[42],[Yes],
  [Resistors 330Ohms],[49],[Yes],
  [Push Switch],[7],[Yes],
  [Breadboards],[7],[Yes],
  [Wires / Auxilary Items],[-],[Yes],
  )

#v(20pt)

== Editor's Notes.

- ESP32 Module is kind of overkill for this purpose. 

- We assume participants have limited knowledge of (or lack thereof) C++ Programming.

- We assume participants have fundamental knowledge on digital circuits.
