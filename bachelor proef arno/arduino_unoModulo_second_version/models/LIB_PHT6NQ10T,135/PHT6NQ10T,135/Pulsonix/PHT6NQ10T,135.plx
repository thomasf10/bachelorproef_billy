PULSONIX_LIBRARY_ASCII "SamacSys ECAD Model"
//527107/36500/2.23/4/4/Transistor

(asciiHeader
	(fileUnits MM)
)
(library Library_1
	(padStyleDef "r195_90"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 0.9) (shapeHeight 1.95))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(padStyleDef "r320_195"
		(holeDiam 0)
		(padShape (layerNumRef 1) (padShapeType Rect)  (shapeWidth 1.95) (shapeHeight 3.2))
		(padShape (layerNumRef 16) (padShapeType Ellipse)  (shapeWidth 0) (shapeHeight 0))
	)
	(textStyleDef "Normal"
		(font
			(fontType Stroke)
			(fontFace "Helvetica")
			(fontHeight 1.27)
			(strokeWidth 0.127)
		)
	)
	(patternDef "SOT230P700X180-4N" (originalName "SOT230P700X180-4N")
		(multiLayer
			(pad (padNum 1) (padStyleRef r195_90) (pt -3, 2.3) (rotation 90))
			(pad (padNum 2) (padStyleRef r195_90) (pt -3, 0) (rotation 90))
			(pad (padNum 3) (padStyleRef r195_90) (pt -3, -2.3) (rotation 90))
			(pad (padNum 4) (padStyleRef r320_195) (pt 3, 0) (rotation 0))
		)
		(layerContents (layerNumRef 18)
			(attr "RefDes" "RefDes" (pt 0, 0) (textStyleRef "Normal") (isVisible True))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.225 3.6) (pt 4.225 3.6) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.225 3.6) (pt 4.225 -3.6) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt 4.225 -3.6) (pt -4.225 -3.6) (width 0.05))
		)
		(layerContents (layerNumRef Courtyard_Top)
			(line (pt -4.225 -3.6) (pt -4.225 3.6) (width 0.05))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.75 3.25) (pt 1.75 3.25) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.75 3.25) (pt 1.75 -3.25) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt 1.75 -3.25) (pt -1.75 -3.25) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.75 -3.25) (pt -1.75 3.25) (width 0.025))
		)
		(layerContents (layerNumRef 28)
			(line (pt -1.75 0.95) (pt 0.55 3.25) (width 0.025))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.675 3.25) (pt 1.675 3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.675 3.25) (pt 1.675 -3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt 1.675 -3.25) (pt -1.675 -3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -1.675 -3.25) (pt -1.675 3.25) (width 0.2))
		)
		(layerContents (layerNumRef 18)
			(line (pt -3.975 4.25) (pt -2.025 4.25) (width 0.2))
		)
	)
	(symbolDef "PHT6NQ10T,135" (originalName "PHT6NQ10T,135")

		(pin (pinNum 1) (pt 0 mils 0 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 230 mils -25 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 2) (pt 0 mils -100 mils) (rotation 0) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 230 mils -125 mils) (rotation 0]) (justify "Left") (textStyleRef "Normal"))
		))
		(pin (pinNum 3) (pt 1500 mils 0 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 1270 mils -25 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(pin (pinNum 4) (pt 1500 mils -100 mils) (rotation 180) (pinLength 200 mils) (pinDisplay (dispPinName false)) (pinName (text (pt 1270 mils -125 mils) (rotation 0]) (justify "Right") (textStyleRef "Normal"))
		))
		(line (pt 200 mils 100 mils) (pt 1300 mils 100 mils) (width 6 mils))
		(line (pt 1300 mils 100 mils) (pt 1300 mils -200 mils) (width 6 mils))
		(line (pt 1300 mils -200 mils) (pt 200 mils -200 mils) (width 6 mils))
		(line (pt 200 mils -200 mils) (pt 200 mils 100 mils) (width 6 mils))
		(attr "RefDes" "RefDes" (pt 1350 mils 300 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))
		(attr "Type" "Type" (pt 1350 mils 200 mils) (justify Left) (isVisible True) (textStyleRef "Normal"))

	)
	(compDef "PHT6NQ10T,135" (originalName "PHT6NQ10T,135") (compHeader (numPins 4) (numParts 1) (refDesPrefix Q)
		)
		(compPin "1" (pinName "GATE") (partNum 1) (symPinNum 1) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "2" (pinName "DRAIN") (partNum 1) (symPinNum 2) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "3" (pinName "SOURCE") (partNum 1) (symPinNum 3) (gateEq 0) (pinEq 0) (pinType Unknown))
		(compPin "4" (pinName "DRAIN (TAB)") (partNum 1) (symPinNum 4) (gateEq 0) (pinEq 0) (pinType Unknown))
		(attachedSymbol (partNum 1) (altType Normal) (symbolName "PHT6NQ10T,135"))
		(attachedPattern (patternNum 1) (patternName "SOT230P700X180-4N")
			(numPads 4)
			(padPinMap
				(padNum 1) (compPinRef "1")
				(padNum 2) (compPinRef "2")
				(padNum 3) (compPinRef "3")
				(padNum 4) (compPinRef "4")
			)
		)
		(attr "Manufacturer_Name" "Nexperia")
		(attr "Manufacturer_Part_Number" "PHT6NQ10T,135")
		(attr "RS Part Number" "1242386")
		(attr "RS Price/Stock" "http://uk.rs-online.com/web/p/products/1242386")
		(attr "Description" "NXP PHT6NQ10T,135 N-channel MOSFET Transistor, 3 A, 100 V, 4-Pin SC-73")
		(attr "<Hyperlink>" "http://docs-europe.electrocomponents.com/webdocs/1538/0900766b815384f4.pdf")
		(attr "<Component Height>" "1.8")
	)

)
