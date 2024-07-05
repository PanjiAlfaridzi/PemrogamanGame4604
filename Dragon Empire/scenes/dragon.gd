extends CharacterBody2D

var speed = 100
var dragon = null
var dragon_chase = false
var current_dir = "none"
var attack_ip = false

func _physics_process(delta):
	dragon_movement(delta)
	#if dragon_chase:
		#position += (dragon.position - position)/speed
		#$AnimatedSprite2D.play("walk_left")
		#if(dragon.position.x - position.x) < 0 :
			#$AnimatedSprite2D.flip_h = false
		#else:
			#$AnimatedSprite2D.flip_h = true
	#else :
		#$AnimatedSprite2D.play("idle")

func _on_detection_body_entered(body):
	dragon = body
	dragon_chase = true


func _on_detection_body_exited(body):
	dragon = null
	dragon_chase = false

func dragon_movement(delta):
	
	if global.interaksi == false:
		if Input.is_action_pressed("ui_right"):
			current_dir = "right"
			play_anim(1)
			velocity.x = speed
			velocity.y = 0 
		elif Input.is_action_pressed("ui_left"):
			current_dir = "left"
			play_anim(1)
			velocity.x = -speed
			velocity.y = 0
		elif Input.is_action_pressed("ui_down"):
			current_dir = "down"
			play_anim(1)
			velocity.y = speed
			velocity.x = 0
		elif Input.is_action_pressed("ui_up"):
			current_dir = "up"
			play_anim(1)
			velocity.y = -speed
			velocity.x = 0
		else:
			play_anim(0)
			velocity.x = 0
			velocity.y = 0
	else:
		play_anim(0)
		velocity.x = 0
		velocity.y = 0
	
	move_and_slide()

func play_anim(movement):

	var dir = current_dir
	var anim = $AnimatedSprite2D
	
	if dir == "right":
		anim.flip_h = true
		if movement == 1:
			anim.play("walk_left")
		elif movement == 0:
			if attack_ip == false:
				anim.play("idle_left")
	if dir == "left":
		anim.flip_h = false
		if movement == 1:
			anim.play("walk_left")
		elif movement == 0:
			if attack_ip == false:
				anim.play("idle_left")
	if dir == "up":
		anim.flip_h = false
		if movement == 1:
			anim.play("walk_top")
		elif movement == 0:
			if attack_ip == false:
				anim.play("idle_top")
	if dir == "down":
		anim.flip_h = false
		if movement == 1:
			anim.play("walk_bottom")
		elif movement == 0:
			if attack_ip == false:
				anim.play("idle")
