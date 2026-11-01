class Pokemon {
    public static final int VIDA_MAXIMA = 100;
    public static int cantidadPokemons = 0;

    private String nombre;
    private String tipo;
    private int vida;
    private int ataque;
    private int nivel;
    private String grito;
    private boolean defendiendo;

    Pokemon(String nombre, String tipo, int vida, int ataque, int nivel,String grito) {
        this.nombre = nombre;
        this.tipo = tipo;
        this.vida = vida;
        this.ataque = ataque;
        this.nivel = nivel;
        this.grito = grito;
        this.defendiendo= false ;

        cantidadPokemons++;
    }


    void setVida(int vida) {

        if (vida < 0) {
            this.vida = 0;
        } else if (vida > VIDA_MAXIMA) {
            this.vida = VIDA_MAXIMA;
        } else {
            this.vida = vida;
        }
    }

    int getVida() {
        return this.vida;
    }

    public String getNombre() {
        return nombre;
    }

    public boolean isDefendiendo() {
        return this.defendiendo;
    }

    void setDefendiendo(boolean defendiendo) {
        this.defendiendo = defendiendo;
    }

    public void defender() {
        this.defendiendo = true;
        System.out.println(this.nombre + " se está defendiendo.");

    }

    private void aplicarDano(Pokemon rival, int dano, String movimiento) {
        int danoFinal = dano;
        if (rival.isDefendiendo()) {
            danoFinal /= 2;
            rival.setDefendiendo(false);
            System.out.println(rival.nombre + " redujo el daño al defenderse!");
        }
        int nuevaVida = rival.getVida() - danoFinal;
        rival.setVida(nuevaVida);

        if (movimiento == null) {
            System.out.println(this.nombre + " ataca a " + rival.nombre + " causando " + danoFinal + " de daño.");
        } else {
            System.out.println(this.nombre + " usa " + movimiento + " contra " + rival.nombre + " causando " + danoFinal + " de daño.");
        }
    }


    public void atacar(Pokemon rival) {
        aplicarDano(rival, this.ataque, null);
    }

    public void atacar(Pokemon rival, String movimiento) {
        int danoEspecial = (int) (this.ataque * 1.5);
        aplicarDano(rival, danoEspecial, movimiento);
    }


    public void curar(int cantidad) {
        int nuevaVida = this.vida + cantidad;
        if (nuevaVida > VIDA_MAXIMA) {
            this.vida = VIDA_MAXIMA;
        } else {
            this.vida = nuevaVida;
        }
        System.out.println(this.nombre + " se ha curado. Vida actual: " + this.vida);
    }




    public boolean vivo() {
        return this.vida > 0;
    }

    public static void mostrarCantidadPokemons() {
        System.out.println("Total de Pokémon registrados: " + cantidadPokemons);
    }

    public void mostrarInformacion() {
        System.out.println("--- Pokémon: " + this.nombre + " ---");
        System.out.println("Tipo   : " + this.tipo);
        System.out.println("Vida   : " + this.vida + " / " + VIDA_MAXIMA);
        System.out.println("Ataque : " + this.ataque);
        System.out.println("Nivel  : " + this.nivel);
    }
    public final void mostrarGrito() {
        System.out.println(this.nombre + " grita: " + this.grito);
    }

}

void main() {
    Pokemon.mostrarCantidadPokemons();
    System.out.println();

    Pokemon charmander = new Pokemon("Charmander", "Fuego", 100, 20, 5, "Char-char");
    Pokemon squirtle = new Pokemon("Squirtle", "Agua", 100, 18, 5, "Squir-squir");
    charmander.mostrarInformacion();
    squirtle.mostrarInformacion();
    System.out.println();

    charmander.mostrarGrito();
    squirtle.mostrarGrito();


    System.out.println("INICIO DE LA PELEA");
    System.out.println();

    System.out.println("[Turno 1]");
    charmander.atacar(squirtle);
    System.out.println("Vida de Squirtle: " + squirtle.getVida());
    System.out.println();

    System.out.println("[Turno 2]");
    squirtle.defender();
    charmander.atacar(squirtle, "Lanzallamas");
    System.out.println("Vida de Squirtle: " + squirtle.getVida());
    System.out.println();

    System.out.println("[Turno 3]");
    squirtle.curar(25);
    squirtle.atacar(charmander, "Pistola Agua");
    System.out.println("Vida de Charmander: " + charmander.getVida());
    System.out.println();

    System.out.println("[Turno 4]");
    charmander.atacar(squirtle, "Lanzallamas");
    System.out.println("Vida de Squirtle: " + squirtle.getVida());
    System.out.println("¿Squirtle sigue vivo? " + squirtle.vivo());
    System.out.println();

    System.out.println("[Turno 5]");
    charmander.atacar(squirtle, "Lanzallamas");
    System.out.println("Vida de Squirtle: " + squirtle.getVida());
    System.out.println("¿Squirtle sigue vivo? " + squirtle.vivo());
    System.out.println();

    System.out.println("FIN DE LA PELEA");






}