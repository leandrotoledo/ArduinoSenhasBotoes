#!/usr/bin/env python
#-*- encoding: utf-8 -*-

# Arduino com 6 botoes e 1 LED RGB para digitacao de senhas (como as de banco)
#
# @author: Leandro Toledo de Souza <leandrotoledo [at] member [dot] fsf [dot] org>
# @author: Pedro Gabriel Dela Rosa <pedrogabriel.delarosa [at] gmail [dot] com>
# @date: 15/05/2013 02:00

import serial   	# apt-get install python-serial

ser = serial.Serial("/dev/ttyACM1", 9600)

def main():
	botoes_input = list()
	botoes_output = {
		'BTN_1': (1, 2),
		'BTN_2': (3, 4),
		'BTN_3': (5, 6),
		'BTN_4': (7, 8),
		'BTN_5': (9, 0),
	}

	senha = '123456'
	senha_resultado = list()

	while True:
		botoes_input.append(ser.readline())
		if (len(botoes_input) >= 6):
			break

	botoes_input = [ i.replace('\r\n', '') for i in botoes_input ]
	index = 0
	for botao in botoes_input:
		if int(senha[index]) in botoes_output[botao]:
			senha_resultado.append(True)
		index = index + 1

	if len(senha_resultado) == 6: 
		print 'T'
		ser.write('T')
	else:
		print 'F'
		ser.write('F')


if __name__ == '__main__':
	while True:
		main()
