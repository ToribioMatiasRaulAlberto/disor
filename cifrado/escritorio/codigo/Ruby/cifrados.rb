require 'tk'

root = TkRoot.new {
 	title "Cifrado" 
 	minsize(400,300)
 }


labelT = TkLabel.new(root){
	text ('Cifrados')
	pack('fill' => 'x')
}
label1 = TkLabel.new(root){
	text 'Ingrese texto a cifrar:'
	pack('fill' => 'x')
}

label2 = TkLabel.new(root){
	text 'Ingrese el desplazamiento:'
	pack('fill' => 'x')
}

label3 = TkLabel.new(root){
	text 'Texto cifrado cesar'
	pack('fill' => 'x')
}

label4 = TkLabel.new(root){
	text 'Texto Invertido'
	pack('fill' => 'x')
}

label5 = TkLabel.new(root){
	text 'Ingrese tamaño de grupos:'
	pack('fill' => 'x')
}

label6 = TkLabel.new(root){
	text 'Texto invertido por grupos'
	pack('fill' => 'x')
}

entry1 = TkEntry.new(root)
entry2 = TkEntry.new(root)
entry3 = TkEntry.new(root)
entry4 = TkEntry.new(root)
entry5 = TkEntry.new(root)
entry6 = TkEntry.new(root)




labelT.place('height' => 25, 'width'  => 180, 'x'   => 100, 'y'   => 10)

entry1.place('height' => 25, 'width'  => 180, 'x'   => 200, 'y'   => 40)
label1.place('height' => 25, 'width'  => 180, 'x'   => 10, 'y'   => 40)

entry2.place('height' => 25, 'width'  => 180, 'x'   => 200, 'y'   => 70)
label2.place('height' => 25, 'width'  => 180, 'x'   => 10, 'y'   => 70)

entry3.place('height' => 25, 'width'  => 180, 'x'   => 200, 'y'   => 100)
label3.place('height' => 25, 'width'  => 180, 'x'   => 10, 'y'   => 100)

entry4.place('height' => 25, 'width'  => 180, 'x'   => 200, 'y'   => 130)
label4.place('height' => 25, 'width'  => 180, 'x'   => 10, 'y'   => 130)

entry5.place('height' => 25, 'width'  => 180, 'x'   => 200, 'y'   => 160)
label5.place('height' => 25, 'width'  => 180, 'x'   => 10, 'y'   => 160)

entry6.place('height' => 25, 'width'  => 180, 'x'   => 200, 'y'   => 190)
label6.place('height' => 25, 'width'  => 180, 'x'   => 10, 'y'   => 190)

	def buscarPosicionDeLetra(letra)
		alfabeto="aábcdeéfghiíjklmnñoópqrstuúvwxyzAÁBCDEÉFGHIÍJKLMNÑOÓPQRSTUÚVWXYZ"
		posicion=-1
		p = 0
		parar = 0
		while parar<alfabeto.length-1
			if letra==alfabeto[parar]
				posicion=parar
			end
			parar=parar+1
		end
		return posicion
	end
	

	def  buscar(letra)
		alfabeto="aábcdeéfghiíjklmnñoópqrstuúvwxyzAÁBCDEÉFGHIÍJKLMNÑOÓPQRSTUÚVWXYZ"
		encontre = false
		parar = 0;
		while parar<alfabeto.length
			if letra==alfabeto[parar]
				encontre=true;
			end
			
			parar=parar+1;
		end
		return encontre;
	end


	def cifrar(texto, desp)
		textoCifrado = ""
		letra = ""
		posicion=0
		alfabeto="aábcdeéfghiíjklmnñoópqrstuúvwxyzAÁBCDEÉFGHIÍJKLMNÑOÓPQRSTUÚVWXYZ"
		 texto.each_char do |caracter|

   			if buscar(caracter)
				posicion = buscarPosicionDeLetra(caracter)
				posicion = posicion + desp
				if posicion > alfabeto.length
					posicion = posicion - alfabeto.length
				end

				textoCifrado = textoCifrado + alfabeto[posicion]
			
			else
				textoCifrado = textoCifrado + caracter
			end

		end 


		return textoCifrado
	end


	def invertirTexto(texto)
		textoInvertido = ""
		stop = texto.length-1

		while stop>=0
			textoInvertido=textoInvertido+texto[stop]
			stop = stop -1
		end
		
		return textoInvertido
	end



	def invertirEnGrupos(texto, grupos)
		textoInvertido=""
		textito=""
		tam=0
		pos=0
		stop=0

		while texto.length>stop do
			if (stop % grupos) == 0
				textoInvertido = textoInvertido + invertirTexto(textito)
				textito = texto[stop]
			else
				textito=textito+texto[stop]
			end
			stop = stop+1
		end
		return textoInvertido+textito
	end







entry1.bind("Key"){

	txt = entry1.get() 
	des = entry2.get().to_i
	agrupacion =  entry5.get().to_i


	entry3.value=cifrar(txt, des);
	entry4.value=invertirTexto(txt)
	entry6.value=invertirEnGrupos(txt, agrupacion)
}

Tk.mainloop