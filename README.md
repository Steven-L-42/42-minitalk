# Minitalk - Projektzusammenfassung

In diesem Minitalk-Projekt habe ich ein Kommunikationsprogramm erstellt, bestehend aus einem Client und einem Server. 

Hier ist eine kurze Zusammenfassung dessen, was ich erreicht habe:

### Server

- Der Server wird zuerst gestartet und gibt seine PID aus.
- Zeichenketten werden schnell empfangen und angezeigt.
- Der Server kann aufeinanderfolgend Zeichenketten von mehreren Clients empfangen, ohne neu gestartet zu werden.
- Die Kommunikation erfolgt ausschließlich über UNIX-Signale (SIGUSR1 und SIGUSR2).

### Client

- Der Client nimmt die PID des Servers und eine zu sendende Zeichenkette als Parameter.
- Der Client sendet die Zeichenkette an den Server.
- Nach dem Empfang gibt der Server die Zeichenkette aus.

### Anzeigezeit des Servers

- Der Server zeigt empfangene Zeichenketten schnell an.

## Bonus

- Der Server bestätigt jede empfangene Nachricht durch Senden eines Signals an den Client.
- Unicode-Zeichen werden unterstützt.

**Zusätzliche Funktionalität:**

- Um die erfolgreiche Übertragung jeder Nachricht zu gewährleisten, sendet der Client zu Beginn die Länge der Nachricht an den Server. 
- Der Server erwartet dann genau diese Länge und sendet ein Bestätigungssignal an den Client, sobald die Übertragung abgeschlossen ist.
- Diese Implementierung gewährleistet eine zuverlässige und vollständige Übertragung von Nachrichten zwischen Client und Server.

Das Projekt verwendet ausführbare Dateien namens client und server, ein Makefile für die Kompilierung ohne Neulinkung, und es basiert auf der libft-Bibliothek. 
Fehler wurden sorgfältig behandelt, und es wurden keine Speicherlecks gefunden. Die Kommunikation erfolgt ausschließlich über die Signale SIGUSR1 und SIGUSR2.
