# Programmable HG-CT Automation Control Unit

A laboratory-built programmable control unit developed to automate a complex **Hydride Generation–Cryotrapping (HG-CT)** analytical system coupled to **Inductively Coupled Plasma Mass Spectrometry (ICP-MS)**.

The system coordinates multiple components of the analytical procedure, including a four-channel peristaltic pump, cryotrap valve, cryotrap heating, spectrometer triggering, and auxiliary devices through fully programmable timed sequences.

The controller was originally developed using an Arduino Mega in 2022 and progressively expanded over several hardware and software generations. The current version is based on an **ESP32** and incorporates Wi-Fi connectivity, a web-based configuration interface, storage of multiple independent analytical programs, and servo-based valve control.

**First unit:** September 2022  
**Current version:** May 2026  
**Physical units constructed:** 3

**Front view of the unit:**

<img width="800" alt="IMG_5154" src="https://github.com/user-attachments/assets/d6364df8-5544-4376-b584-43f1cf7e2c61" />

<br>
<br>

## Overview

The control unit was developed to automate an analytical procedure requiring precise coordination of several independent devices.

The current system provides:

- 12 programmable sequential steps
- Independent control of four peristaltic pump channels
- Individual pump speed and direction control
- Servo-actuated cryotrap valve control
- Cryotrap heating control
- ICP-MS/MS reading trigger
- Two auxiliary relay outputs
- Programmable buzzer notification
- Local LCD and pushbutton interface
- Wi-Fi configuration through an integrated web server
- Storage of three independent analytical programs
- Non-volatile parameter storage

The controller executes the complete analytical sequence automatically after the method parameters have been configured.

<br>

## System Architecture

```text id="wwsjio"
                         ┌──────────────────────┐
                         │        ESP32         │
                         │  Programmable Control│
                         │        Unit          │
                         └──────────┬───────────┘
                                    │
          ┌─────────────────────────┼────────────────────────┐ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─ ─┐
          │                         │                        │                        │
          ▼                         ▼                        ▼                        ▼
 ┌─────────────────┐      ┌─────────────────┐      ┌─────────────────┐      ┌─────────────────┐
 │  4-Channel      │      │   HG-CT System  │      │    ICP-MS/MS    │      │  2 additional   │
 │ Peristaltic Pump│      │                 │      │                 │      │     relays      │
 │                 │      │ Servo / Heating │      │ Reading Trigger │      │                 │
 │ RPM + Direction │      │                 │      │                 │      │   250 V/10 A    │
 └─────────────────┘      └─────────────────┘      └─────────────────┘      └─────────────────┘
```

The programmable control unit acts as the central controller of the analytical system, synchronizing fluid handling, cryotrapping, heating, valve operation, and instrumental signal acquisition.

<br>

## HG-CT Control

The controller coordinates the different stages of the hydride generation and cryotrapping procedure.

A typical analytical cycle involves:

```text id="sqeuv5"
Sample / reagent delivery
        ↓
Hydride generation
        ↓
Cryogenic trapping
        ↓
System flushing
        ↓
Cryotrap valve switching
        ↓
Cryotrap heating
        ↓
Release of trapped species
        ↓
ICP-MS/MS signal acquisition
```

In the earlier versions of the system, liquid nitrogen control was performed using a **solenoid valve**. In the current ESP32 version, this was replaced by a **servo-actuated valve**, allowing the valve position to be controlled directly by the microcontroller without requiring solenoid actuation.

The automation replaces a sequence of manually coordinated operations with a reproducible programmable procedure.

<br>

### Servo-Actuated Valve

The current version uses a servo motor to mechanically actuate the cryotrap valve. Valve opening and closing are integrated into the programmable sequence and automatically synchronized with the other stages of the analytical cycle.

**Servo-actuated valve operation:**


https://github.com/user-attachments/assets/ff7d8ff2-8369-44f6-a764-7405395b6b20

<br>
<br>

## Programmable Sequence

The analytical procedure is divided into **12 programmable steps**.

For each step, the operator can independently configure:

| Parameter | Function |
|---|---|
| **Time** | Duration of the step |
| **Read** | Triggers analytical signal acquisition |
| **Valve** | Controls the servo-actuated CT valve |
| **Heat** | Controls cryotrap heating |
| **Relay 1** | Auxiliary output |
| **Relay 2** | Auxiliary output |
| **Beep** | Acoustic indication |
| **RPM 1–4** | Speed of each peristaltic pump channel |
| **Direction 1–4** | CW/CCW direction of each pump channel |

This architecture allows complex analytical procedures to be constructed as a sequence of configurable operations.

Steps that are not required for a particular method can be disabled by assigning a time of zero.

<br>

## Peristaltic Pump Control

The system communicates directly with a **four-channel Ismatec Reglo ICC peristaltic pump** through its RS-232 interface.

Since the microcontroller operates with TTL-level serial communication, a **MAX3232 transceiver module** is used for TTL-to-RS-232 level conversion between the control unit and the pump.

The communication protocol was implemented based on the command set provided in the manufacturer's pump manual, allowing the controller to independently configure each of the four channels for:

- rotational speed (RPM)
- rotation direction (CW/CCW)
- start/stop operation

These commands are integrated directly into the programmable sequence, allowing each pump channel to operate with different parameters during each of the **12 steps**.

This enables the automated coordination of sample, reagents, rinse solutions, and waste flows with the other stages of the analytical procedure, without requiring manual pump operation.

**Front and back view of the peristaltic pump used and the commands for channel operation via RS-232 input:**

<img width="3292" height="1197" alt="1698615_ismatec-reglo-icc-digital-peristaltic-pump-4-channel-12-roller_1170928_415-horz" src="https://github.com/user-attachments/assets/3bb6dc30-34a3-4e78-aa9d-9d8a64ae051b" />

<br>
<br>

## Web Interface

The current ESP32 version creates its own Wi-Fi network and hosts an integrated configuration page.

No dedicated computer software is required to configure the controller. The interface can be accessed directly from a web browser after connecting to the controller's Wi-Fi network.

```text id="9z5t9e"
Wi-Fi network: STEP MODULE WIFI
Address: 192.168.4.1
```

The web interface displays the complete **12-step analytical sequence as a configurable table**.

<img width="1056" height="766" alt="image" src="https://github.com/user-attachments/assets/c76ac2f7-2c5d-40d6-95c4-084cd9073b33" />

<br>

For every step, the user can configure:

- execution time
- spectrometer reading trigger
- servo-actuated cryotrap valve
- cryotrap heating
- auxiliary relays
- acoustic notification
- RPM of each of the four pump channels
- CW/CCW direction of each pump channel

Programs can be configured, saved, selected, and started through the interface.

<br>

## Multiple Program Storage

One of the main developments of the current version is the ability to store **three independent analytical programs**.

Each program contains its own complete 12-step sequence, including step duration, reading commands, valve and heating states, auxiliary relay states, pump speeds and directions, and acoustic notifications.

Each program can also be assigned an individual name.

The program parameters and names are stored in non-volatile memory, allowing the configured analytical methods to remain available after the controller is powered off.

This makes it possible to switch between different analytical procedures without manually reconfiguring every parameter of the sequence.

<img width="302" height="102" alt="image" src="https://github.com/user-attachments/assets/01dc9cb9-99c9-42db-ba90-0fc4406ab260" />

<br>
<br>

## Local User Interface

In addition to the web interface, the controller can be operated directly from the control box.

The local interface includes:

- 16×2 LCD
- START button
- CANCEL button
- MENU button
- BACK button

The LCD displays information such as the selected program, current operating state, configuration parameters, sequence step, and elapsed time.

<br>

## Hardware Units

Three physical control units were constructed during the development of the project.

| Unit | Date | Platform | Configuration |
|---|---|---|---|
| **Unit 1** | September 2022 | Arduino Mega | Original system with two independent voltage outputs for resistive heating and solenoid valve control |
| **Unit 2** | January 2026 | Arduino Mega | Revised system with one voltage output for resistive heating and solenoid valve control; constructed for a collaborating laboratory in China |
| **Unit 3** | February 2026 | ESP32 | Current system with servo-actuated valve, Wi-Fi interface, and multi-program control |

<br>

<img width="3300" height="1383" alt="box 1-horz" src="https://github.com/user-attachments/assets/dcb8cf5b-cc83-44bb-b5db-4ebabadea068" />


<br>
<br>

## Internal Hardware

The internal hardware integrates the power supplies, control electronics, communication modules, relays, connectors, and wiring required to interface the ESP32 with the different components of the analytical system.

The images below show the internal electronics and wiring of the control unit, as well as the rear panel and external connections.

**Internal electronics and wiring:**

<table>
  <tr>
    <td width="50%">
      <img width="1330" height="1667" alt="IMG_8409" src="https://github.com/user-attachments/assets/2e1afe82-57a5-43ae-a691-3772196953d2" />
    </td>
    <td width="50%">
      <img width="1302" height="1637" alt="IMG_8410" src="https://github.com/user-attachments/assets/074b3d97-53aa-4348-a353-5a83afba8f96" />
    </td>
  </tr>
</table>

<br>
<br>

**Rear panel and connections:**

<img width="2098" height="1498" alt="IMG_5157" src="https://github.com/user-attachments/assets/815b514c-03b6-49fc-b85f-3e02bf1c330d" />


<br>
<br>

## Firmware Development

The firmware evolved continuously as new requirements and methods of configuration were introduced.

Five major software versions are preserved in this repository.

| Version | Platform | Main Development |
|---|---|---|
| **V1** | Arduino Mega | Initial programmable controller with local interface and multi-device sequence control |
| **V2** | Arduino Mega | Added serial communication for transferring sequence parameters from Excel |
| **V3** | ESP32 | Migrated the complete control system from Arduino Mega to ESP32 |
| **V4** | ESP32 | Added Wi-Fi connectivity and an integrated web server for browser-based configuration |
| **V5** | ESP32 | Added three independent stored programs, program naming, expanded web interface, servo-actuated valve control, and the current complete control architecture |

In **V2**, sequence parameters could be transferred directly from Microsoft Excel to the Arduino Mega using **Excel Data Streamer** and the Arduino serial connection. The Excel file used with this version is included in the repository to demonstrate how the parameters were organized and transferred to the controller.

To use this interface, **Data Streamer** must be enabled in Excel and the Arduino Mega selected through **Data Streamer → Connect a Device**.

The historical versions are retained to document the technical evolution of the project.

<br>

## From Arduino Mega to ESP32

During operation, the Arduino Mega-based units occasionally experienced **unexpected resets**. Several measures were tested, including improved suppression of electrical interference associated with solenoid valve switching and power supply stabilization, but the issue persisted.

The system was subsequently migrated to an **ESP32**, after which the reset issue was no longer observed. The migration also enabled the introduction of **Wi-Fi connectivity and an embedded web server**, forming the basis for the current multi-program version.

<br>

## Research Application

The control system was developed and used as part of a scientific study involving the simultaneous ultratrace speciation of **Sb, As, and Ge in natural waters** by HG-CT-ICP-MS/MS.

The system used in the published study was based on an **earlier Arduino version**, in which the cryotrap liquid nitrogen flow was controlled using a **solenoid valve**. The published experimental description identifies the system as being completely controlled by an in-house-built programmable control unit responsible for the operation of the peristaltic pump, solenoid valve, U-tube heating, and spectrometer triggering.

The construction of the control unit was also acknowledged by the authors of the publication:

> “We warmly thank Gilberto Coelho Junior for the construction of the HG-CT control box.”

**Publication:**  
https://doi.org/10.1016/j.sab.2026.107501

<br>

## Author

**Gilberto Coelho**

Electronics & Automation Developer

This project was developed as part of laboratory automation and analytical instrumentation research.
