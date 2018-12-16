class Home
  include Inesita::Component

  def render
      h1 do
        text "Cifrados"
      end
      
      label do
        text "Ingrese texto a cifrar: "
      end
      
      br
      
      textarea rows: 4, cols: 40 do
        text ""
      end
      
      br
      br
      br

      #component Counter, props: {header: 'Vamos a cifrar'}

      table do
          tr do
              td do
                ul do
                    h1 do
                      text "Cifrado Cesar"
                    end

                    label do
                      text "Indique desplazamiento"
                    end

                    input type:"number"do
                    end

                    br
                    label do
                      text "texto cifrado"
                    end
                    br
                    textarea rows:4, cols:40 do
                      text ""
                    end


                end
              end


              td do
                ul do
                  h1 do
                    text "Cifrado por trasposicion"
                  end

                  label do
                    text "Texto cifrado"
                  end

                  br br br

                  textarea rows:4, cols:40 do
                      text ""
                  end
                end
              end

             td do
                ul do
                  h1 do
                    text "Cifrado por trasposicion en grupos"
                  end

                  label do
                    text "Indique tamaño de grupos:"
                  end
                
                  
                  input type:"number"do
                  end
                  br
                  label do
                    text "Texto cifrado"
                  end

                  br br br

                  textarea rows:4, cols:40 do
                      text ""
                  end
                end
              end


          end

      end

    end
  end

