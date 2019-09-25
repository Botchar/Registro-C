#define DIRECCION_BASE "C:/xampp/htdocs/Formacion/1.-Lenguajes/1.-C/1.-Temario/56.-Proyecto Final/Registro-C/registro_c/MiBaseDatos.db"

#define CREATE_TABLES \
    "CREATE TABLE IF NOT EXISTS lugar ("\
      "id_lugar INT NOT NULL,"\
      "id_descripcion VARCHAR(100) NULL,"\
      "tipo VARCHAR(45) NULL,"\
      "PRIMARY KEY (id_lugar))"\
    "ENGINE = InnoDB;"\
    ""\
    ""\
    "CREATE TABLE IF NOT EXISTS club ("\
      "id_club INT NOT NULL AUTO_INCREMENT,"\
      "nombre VARCHAR(100) NULL,"\
      "colonia VARCHAR(100) NULL,"\
      "canchas_duras INT NULL,"\
      "canchas_arcilla INT NULL,"\
      "canchas_pasto INT NULL,"\
      "vigencia DATETIME NULL,"\
      "id_estado INT NULL,"\
      "id_alcaldia INT NULL,"\
      "tipo VARCHAR(500) NULL,"\
      "PRIMARY KEY (id_club),"\
      "INDEX id_alcaldia_idx (id_alcaldia ASC) VISIBLE,"\
      "INDEX id_estado_idx (id_estado ASC) VISIBLE,"\
      "CONSTRAINT id_estado"\
        "FOREIGN KEY (id_estado)"\
        "REFERENCES lugar (id_lugar)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT id_alcaldia"\
        "FOREIGN KEY (id_alcaldia)"\
        "REFERENCES lugar (id_lugar)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION)"\
    "ENGINE = InnoDB;"\
    ""\
    ""\
    "CREATE TABLE IF NOT EXISTS categoria ("\
      "id_categoria INT NOT NULL,"\
      "descripcion VARCHAR(100) NULL,"\
      "PRIMARY KEY (id_categoria))"\
    "ENGINE = InnoDB;"\
    ""\
    ""\
    "CREATE TABLE IF NOT EXISTS torneo ("\
      "id_torneo INT NOT NULL,"\
      "nombre VARCHAR(200) NULL,"\
      "fecha_inicio DATETIME NULL,"\
      "fecha_fin DATETIME NULL,"\
      "costo DECIMAL(500) NULL,"\
      "PRIMARY KEY (id_torneo))"\
    "ENGINE = InnoDB;"\
    ""\
    ""\
    "CREATE TABLE IF NOT EXISTS evento_torneo ("\
      "id_evento INT NOT NULL,"\
      "id_club INT NULL,"\
      "id_torneo INT NULL,"\
      "id_categoria INT NULL,"\
      "PRIMARY KEY (id_evento),"\
      "INDEX id_club_idx (id_club ASC) VISIBLE,"\
      "INDEX id_torneo_idx (id_torneo ASC) VISIBLE,"\
      "INDEX id_categoria_idx (id_categoria ASC) VISIBLE,"\
      "CONSTRAINT id_club"\
        "FOREIGN KEY (id_club)"\
        "REFERENCES club (id_club)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT id_torneo"\
        "FOREIGN KEY (id_torneo)"\
        "REFERENCES torneo (id_torneo)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT id_categoria"\
        "FOREIGN KEY (id_categoria)"\
        "REFERENCES categoria (id_categoria)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION)"\
    "ENGINE = InnoDB;"\
    ""\
    ""\
    "CREATE TABLE IF NOT EXISTS jugador ("\
      "id_jugador INT NOT NULL,"\
      "nombre VARCHAR(100) NULL,"\
      "apellido_paterno VARCHAR(100) NULL,"\
      "apellido_materno VARCHAR(100) NULL,"\
      "fecha_nacimiento DATETIME NULL,"\
      "id_club INT NULL,"\
      "estado INT NULL,"\
      "alcaldia INT NULL,"\
      "vigencia DATETIME NULL,"\
      "PRIMARY KEY (id_jugador),"\
      "INDEX id_club_idx (id_club ASC) VISIBLE,"\
      "INDEX estado_idx (estado ASC) VISIBLE,"\
      "INDEX alcaldia_idx (alcaldia ASC) VISIBLE,"\
      "CONSTRAINT id_club"\
        "FOREIGN KEY (id_club)"\
        "REFERENCES club (id_club)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT estado"\
        "FOREIGN KEY (estado)"\
        "REFERENCES lugar (id_lugar)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT alcaldia"\
        "FOREIGN KEY (alcaldia)"\
        "REFERENCES lugar (id_lugar)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION)"\
    "ENGINE = InnoDB;"\
    ""\
    ""\
    "CREATE TABLE IF NOT EXISTS inscripcion ("\
      "id_inscripcion INT NOT NULL,"\
      "id_torneo INT NULL,"\
      "id_jugador INT NULL,"\
      "id_categoria INT NULL,"\
      "ronda VARCHAR(45) NULL,"\
      "puntos VARCHAR(1000) NULL,"\
      "pagado TINYINT NULL,"\
      "PRIMARY KEY (id_inscripcion),"\
      "INDEX id_torneo_idx (id_torneo ASC) VISIBLE,"\
      "INDEX id_jugador_idx (id_jugador ASC) VISIBLE,"\
      "INDEX id_categoria_idx (id_categoria ASC) VISIBLE,"\
      "CONSTRAINT id_torneo"\
        "FOREIGN KEY (id_torneo)"\
        "REFERENCES torneo (id_torneo)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT id_jugador"\
        "FOREIGN KEY (id_jugador)"\
        "REFERENCES jugador (id_jugador)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION,"\
      "CONSTRAINT id_categoria"\
        "FOREIGN KEY (id_categoria)"\
        "REFERENCES categoria (id_categoria)"\
        "ON DELETE NO ACTION"\
        "ON UPDATE NO ACTION)"\
    "ENGINE = InnoDB;"
